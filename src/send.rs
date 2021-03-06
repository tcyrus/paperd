// This file is part of paperd, the PaperMC server daemon
// Copyright (C) 2019 Kyle Wood (DemonWav)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, version 3 only.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

use crate::log::{find_log_file, tail};
use crate::messaging;
use crate::messaging::MessageHandler;
use crate::protocol::check_protocol;
use crate::util::get_pid;
use clap::ArgMatches;
use serde::Serialize;
use std::path::Path;

pub fn send(sub_m: &ArgMatches) -> Result<(), i32> {
    let (pid_file, _) = get_pid(sub_m)?;
    check_protocol(&pid_file)?;

    let command = match sub_m.value_of("COMMAND") {
        Some(s) => s,
        None => {
            eprintln!("No command given.");
            return Err(1);
        }
    };

    send_command(&pid_file, command)?;

    if sub_m.is_present("TAIL") {
        let log_file = find_log_file(&pid_file)?;
        return tail(log_file, 0, true);
    }

    return Ok(());
}

pub fn send_command<P: AsRef<Path>>(pid_file: P, cmd: &str) -> Result<(), i32> {
    let message = SendCommandMessage {
        message: cmd.to_string(),
    };

    let chan = messaging::open_message_channel(pid_file.as_ref())?;
    return match chan.send_message::<SendCommandMessage>(message) {
        Ok(_) => Ok(()),
        Err(e) => Err(e),
    };
}

#[derive(Serialize)]
struct SendCommandMessage {
    #[serde(rename = "message")]
    message: String,
}

impl MessageHandler for SendCommandMessage {
    fn type_id() -> i16 {
        return 4;
    }

    fn expect_response() -> bool {
        return false;
    }
}
