#ifndef MESSAGE_CENTER_H
#define MESSAGE_CENTER_H

#include "FreeRTOS.h"
#include "queue.h"

#define MESSAGE_QUEUE_LENGTH 10           // 娑堟伅闃熷垪闀垮害
#define MESSAGE_SEND_TIMEOUT pdMS_TO_TICKS(100)  // 鍙戦�佹秷鎭秴鏃舵椂闂�

#define MESSAGE_CENTER_TASK_STACK_SIZE configMINIMAL_STACK_SIZE  // 娑堟伅涓績浠诲姟鍫嗘爤澶у皬
//#define MESSAGE_CENTER_TASK_PRIORITY tskIDLE_PRIORITY + 1        // 娑堟伅涓績浠诲姟浼樺厛绾�

typedef enum {
    MSG_PRIORITY_HIGH,    // 楂樹紭鍏堢骇娑堟伅
    MSG_PRIORITY_MEDIUM,  // 涓紭鍏堢骇娑堟伅
    MSG_PRIORITY_LOW      // 浣庝紭鍏堢骇娑堟伅
} MessagePriority;

typedef enum {
    MSG_RESULT_SUCCESS,         // 娑堟伅澶勭悊鎴愬姛
    MSG_RESULT_ERROR,           // 娑堟伅澶勭悊鍑洪敊
    MSG_RESULT_CRITICAL_ERROR   // 娑堟伅澶勭悊鍑虹幇涓ラ噸閿欒
} MessageResult;

typedef struct {
    int id;                 // 娑堟伅ID
    MessagePriority priority;  // 娑堟伅浼樺厛绾�
    MessageResult result;   // 娑堟伅澶勭悊缁撴灉
    
    union {
        int error_code;     // 閿欒鐮�
        char error_message[256];  // 閿欒娑堟伅
        // 鍏朵粬娑堟伅鏁版嵁
    } data;  // 娑堟伅鏁版嵁
} Message;

void message_center_init();  // 鍒濆鍖栨秷鎭腑蹇�

int message_send(Message *msg);  // 鍙戦�佹秷鎭�

int message_receive(Message *msg, TickType_t xTicksToWait);  // 鎺ユ敹娑堟伅

void handle_high_priority_message(Message *msg);    // 澶勭悊楂樹紭鍏堢骇娑堟伅
void handle_medium_priority_message(Message *msg);  // 澶勭悊涓紭鍏堢骇娑堟伅
void handle_low_priority_message(Message *msg);     // 澶勭悊浣庝紭鍏堢骇娑堟伅

#endif // MESSAGE_CENTER_H
