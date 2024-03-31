#include "FreeRTOS.h"
#include "queue.h"
#include "message_center.h"
#include "error_handling.h"

static QueueHandle_t xMessageQueue;

static void MessageCenterTask( void *pvParameters );

// 鍒濆鍖栨秷鎭腑蹇�
void message_center_init() {
    xMessageQueue = xQueueCreate(MESSAGE_QUEUE_LENGTH, sizeof(Message));
    
    xTaskCreate(MessageCenterTask, "MessageCenter", MESSAGE_CENTER_TASK_STACK_SIZE, NULL, 1, NULL);
}

// 鍙戦�佹秷鎭�
int message_send(Message *msg) {
    // 妫�鏌ユ秷鎭槦鍒楁槸鍚﹀凡婊�
    if (xQueueSend(xMessageQueue, msg, MESSAGE_SEND_TIMEOUT) != pdPASS) {
        // 璁板綍閿欒
        error_log(ERROR_MESSAGE_QUEUE_FULL, "Message queue is full");
        return -1;
    }
    return 0;
}

// 鎺ユ敹娑堟伅
int message_receive(Message *msg, TickType_t xTicksToWait) {
    // 浠庢秷鎭槦鍒椾腑鎺ユ敹娑堟伅
    if (xQueueReceive(xMessageQueue, msg, xTicksToWait) != pdPASS) {
        return -1;
    }
    return 0;
}

static void MessageCenterTask( void *pvParameters ) {
    Message msg;
    
    while (1) {
        // 鎺ユ敹娑堟伅
        if (message_receive(&msg, portMAX_DELAY) == 0) {
            switch (msg.priority) {
                case MSG_PRIORITY_HIGH:
//                    handle_high_priority_message(&msg);
                    break;
                    
                case MSG_PRIORITY_MEDIUM:
//                    handle_medium_priority_message(&msg);
                    break;
                    
                case MSG_PRIORITY_LOW:
//                    handle_low_priority_message(&msg);
                    break;
                    
                default:
                    error_log(ERROR_INVALID_MESSAGE_PRIORITY, "Invalid message priority");
                    break;
            }
            
            // 妫�鏌ユ秷鎭鐞嗙粨鏋�
            if (msg.result != MSG_RESULT_SUCCESS) {
                // 璁板綍娑堟伅澶勭悊閿欒
                error_log(ERROR_MESSAGE_HANDLING_FAILED, "Message handling failed");
                
                // 濡傛灉鏄弗閲嶉敊璇�,鍚戜笂绾т簯鏈嶅姟鍣ㄥ彂閫侀�氱煡
                if (msg.result == MSG_RESULT_CRITICAL_ERROR) {
//                    cloud_notify_error(&msg);
                }
            }
        }
    }
}
