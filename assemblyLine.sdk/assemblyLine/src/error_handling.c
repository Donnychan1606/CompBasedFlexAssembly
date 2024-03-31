#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "error.log"
#define MAX_ERROR_MSG_LEN 256

#define MSG_PRIORITY_HIGH   1
#define MSG_PRIORITY_MEDIUM 2
#define MSG_PRIORITY_LOW    3

#define MSG_RESULT_SUCCESS  0
#define MSG_RESULT_FAILURE  1

#define ERROR_CRITICAL      1
#define ERROR_MAJOR         2
#define ERROR_MINOR         3
#define ERROR_WARNING       4

void error_log(int error_code, const char *error_message) {
    // 鎵撳嵃閿欒淇℃伅鍒版帶鍒跺彴
    printf("Error %d: %s\n", error_code, error_message);
    
    // 鍐欏叆閿欒淇℃伅鍒版棩蹇楁枃浠�
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        printf("Failed to open log file.\n");
        return;
    }
    
    // 鑾峰彇褰撳墠鏃堕棿
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    
    // 鍐欏叆閿欒淇℃伅鍜屾椂闂村埌鏂囦欢
    fprintf(fp, "[%s] Error %d: %s\n", time_str, error_code, error_message);
    fclose(fp);
    
    // 鏍规嵁閿欒鐮佽繘琛岀壒瀹氱殑閿欒澶勭悊
    switch (error_code) {
        case ERROR_MESSAGE_QUEUE_FULL:
            // 澶勭悊娑堟伅闃熷垪宸叉弧鐨勯敊璇�
            printf("Message queue is full. Clearing the queue.\n");
            clear_message_queue();
            break;
        
        case ERROR_INVALID_MESSAGE_PRIORITY:
            // 澶勭悊鏃犳晥娑堟伅浼樺厛绾х殑閿欒
            printf("Invalid message priority. Discarding the message.\n");
            break;
        
        case ERROR_MESSAGE_HANDLING_FAILED:
            // 澶勭悊娑堟伅澶勭悊澶辫触鐨勯敊璇�
            printf("Message handling failed. Retrying...\n");
            retry_message_handling();
            break;
        
        
        default:
            // 澶勭悊鏈煡閿欒鐮�
            printf("Unknown error code.\n");
            break;
    }
    
    // 濡傛灉鏄弗閲嶉敊璇�,缁堟绋嬪簭
    if (is_critical_error(error_code)) {
        printf("Critical error occurred. Terminating the program.\n");
        exit(1);
    }
}

int is_critical_error(int error_code) {
    // 鍒ゆ柇閿欒鐮佹槸鍚﹁〃绀轰弗閲嶉敊璇�
    // 鍙互鏍规嵁闇�瑕佷慨鏀硅繖涓嚱鏁�
    return error_code == ERROR_CRITICAL;
}

void clear_message_queue() {
//    Message msg;
//
//    // 寰幆浠庢秷鎭槦鍒椾腑鍙栧嚭娑堟伅,鐩村埌闃熷垪涓虹┖
//    while (xQueueReceive(xMessageQueue, &msg, 0) == pdTRUE) {
//        // 澶勭悊琚彇鍑虹殑娑堟伅
//        switch (msg.priority) {
//            case MSG_PRIORITY_HIGH:
//                // 澶勭悊楂樹紭鍏堢骇娑堟伅
//                handle_high_priority_message(&msg);
//                break;
//
//            case MSG_PRIORITY_MEDIUM:
//                // 澶勭悊涓紭鍏堢骇娑堟伅
//                handle_medium_priority_message(&msg);
//                break;
//
//            case MSG_PRIORITY_LOW:
//                // 澶勭悊浣庝紭鍏堢骇娑堟伅
//                handle_low_priority_message(&msg);
//                break;
//
//            default:
//                // 璁板綍鏃犳晥鐨勬秷鎭紭鍏堢骇
//                error_log(ERROR_INVALID_MESSAGE_PRIORITY, "Invalid message priority");
//                break;
//        }
//    }
//
//    printf("Message queue cleared.\n");
}

void retry_message_handling() {
//    Message msg;
//    int retry_count = 0;
//
//    // 浠庢秷鎭槦鍒椾腑鍙栧嚭娑堟伅
//    if (xQueueReceive(xMessageQueue, &msg, 0) == pdTRUE) {
//        // 灏濊瘯澶勭悊娑堟伅,鏈�澶氶噸璇�3娆�
//        while (retry_count < 3) {
//            switch (msg.priority) {
//                case MSG_PRIORITY_HIGH:
//                    // 澶勭悊楂樹紭鍏堢骇娑堟伅
//                    handle_high_priority_message(&msg);
//                    break;
//
//                case MSG_PRIORITY_MEDIUM:
//                    // 澶勭悊涓紭鍏堢骇娑堟伅
//                    handle_medium_priority_message(&msg);
//                    break;
//
//                case MSG_PRIORITY_LOW:
//                    // 澶勭悊浣庝紭鍏堢骇娑堟伅
//                    handle_low_priority_message(&msg);
//                    break;
//
//                default:
//                    // 璁板綍鏃犳晥鐨勬秷鎭紭鍏堢骇
//                    error_log(ERROR_INVALID_MESSAGE_PRIORITY, "Invalid message priority");
//                    break;
//            }
//
//            // 濡傛灉娑堟伅澶勭悊鎴愬姛,璺冲嚭寰幆
//            if (msg.result == MSG_RESULT_SUCCESS) {
//                break;
//            }
//
//            retry_count++;
//            printf("Retrying message handling. Retry count: %d\n", retry_count);
//        }
//
//        // 濡傛灉閲嶈瘯娆℃暟杈惧埌涓婇檺,璁板綍閿欒骞堕�氱煡浜戞湇鍔″櫒
//        if (retry_count == 3 && msg.result != MSG_RESULT_SUCCESS) {
//            error_log(ERROR_MESSAGE_HANDLING_FAILED, "Message handling failed after 3 retries");
//            cloud_notify_error(&msg);
//        }
//    } else {
//        printf("No message found for retrying.\n");
//    }
}
