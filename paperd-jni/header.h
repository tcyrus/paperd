/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_destroystokyo_paper_daemon_PaperDaemonJni */

#ifndef _Included_com_destroystokyo_paper_daemon_PaperDaemonJni
#define _Included_com_destroystokyo_paper_daemon_PaperDaemonJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_destroystokyo_paper_daemon_PaperDaemonJni
 * Method:    createQueue
 * Signature: (Ljava/nio/file/Path;)I
 */
JNIEXPORT jint JNICALL Java_com_destroystokyo_paper_daemon_PaperDaemonJni_createQueue
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_destroystokyo_paper_daemon_PaperDaemonJni
 * Method:    sendMessage
 * Signature: (ILcom/destroystokyo/paper/daemon/MsgBuf;)V
 */
JNIEXPORT void JNICALL Java_com_destroystokyo_paper_daemon_PaperDaemonJni_sendMessage
  (JNIEnv *, jclass, jint, jobject);

/*
 * Class:     com_destroystokyo_paper_daemon_PaperDaemonJni
 * Method:    receiveMessage
 * Signature: (I)Lcom/destroystokyo/paper/daemon/MsgBuf;
 */
JNIEXPORT jobject JNICALL Java_com_destroystokyo_paper_daemon_PaperDaemonJni_receiveMessage
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_destroystokyo_paper_daemon_PaperDaemonJni
 * Method:    deleteQueue
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_destroystokyo_paper_daemon_PaperDaemonJni_deleteQueue
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_destroystokyo_paper_daemon_PaperDaemonJni
 * Method:    pidExists
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_destroystokyo_paper_daemon_PaperDaemonJni_pidExists
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif