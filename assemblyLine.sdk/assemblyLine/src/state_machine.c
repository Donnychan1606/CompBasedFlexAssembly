#include <FreeRTOS.h>
#include <task.h>
#include "state_machine.h"
#include "message_center.h"

typedef enum {
    STATE_INIT,
    STATE_IDLE,
    STATE_LOADING,
    STATE_PROCESSING,
    STATE_UNLOADING,
    STATE_PRINT_READY,
    STATE_PRINT_BUSY
} State;

State current_state = STATE_INIT;

void state_machine_task(void *pvParameters)
{
    Message msg;

    while (1) {
        // 绛夊緟娑堟伅
        //xQueueReceive(message_queue, &msg, portMAX_DELAY);

        switch (current_state) {
            case STATE_INIT:
                // 鍒濆鍖栫姸鎬�
                //xQueueSend(message_queue, &(Message){MSG_MOTOR_INIT}, 0);
                //xQueueSend(message_queue, &(Message){MSG_SENSOR_INIT}, 0);
                current_state = STATE_IDLE;
                break;

            case STATE_IDLE:
                if (msg.id == MSG_START) {
                    // 鍒囨崲鍒颁笂鏂欑姸鎬�
                    current_state = STATE_LOADING;
                    // 鍚姩浼犻�佸甫鍜屾満姊拌噦
                    //xQueueSend(message_queue, &(Message){MSG_CONVEYOR_START}, 0);
                    //xQueueSend(message_queue, &(Message){MSG_ROBOTIC_ARM_LOAD}, 0);
                }
                break;

            case STATE_LOADING:
                if (msg.id == MSG_LOADING_DONE) {
                    // 鍒囨崲鍒板姞宸ョ姸鎬�
                    current_state = STATE_PROCESSING; 
                    // 鍚姩涓夎酱骞冲彴鍜屾墦鍗板ご
                    //xQueueSend(message_queue, &(Message){MSG_THREE_AXES_PLATFORM_START}, 0);
                    //xQueueSend(message_queue, &(Message){MSG_PRINT_HEAD_START}, 0);
                }
                break;

            case STATE_PROCESSING:
                if (msg.id == MSG_PROCESSING_DONE) {
                    // 鍒囨崲鍒颁笅鏂欑姸鎬�
                    current_state = STATE_UNLOADING;
                    // 鍚姩浼犻�佸甫鍜屾満姊拌噦
                    //xQueueSend(message_queue, &(Message){MSG_CONVEYOR_START}, 0);
                    //xQueueSend(message_queue, &(Message){MSG_ROBOTIC_ARM_UNLOAD}, 0);
                }
                break;

            case STATE_UNLOADING:
                if (msg.id == MSG_UNLOADING_DONE) {
                    // 鍒囨崲鍒扮┖闂茬姸鎬�
                    current_state = STATE_IDLE;
                }
                break;

            case STATE_PRINT_READY:
                if (msg.id == MSG_PRINT_START) {
                    // 鍒囨崲鍒版墦鍗扮姸鎬�
                    current_state = STATE_PRINT_BUSY;
                    // 鍚姩鎵撳嵃澶�
                    //xQueueSend(message_queue, &(Message){MSG_PRINT_HEAD_START}, 0);
                }
                break;

            case STATE_PRINT_BUSY:
                if (msg.id == MSG_PRINT_DONE) {
                    // 鍒囨崲鍒版墦鍗板氨缁姸鎬�
                    current_state = STATE_PRINT_READY;
                }
                break;

            default:
                break;
        }
    }
}
