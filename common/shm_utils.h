/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SHM_UTILS_H
#define SHM_UTILS_H

#include <errno.h>
#include <securec.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/shm.h>

#define MAX_DATA_LENGTH      1024
#define MAX_WAIT_TIMEOUT      10
#define SHM_SEND_KEY              123456
#define SHM_RECV_KEY              123466

struct shared_use_st
{
    int written;//作为一个标志，非0：表示可读，0表示可写
    char data[MAX_DATA_LENGTH];//记录写入和读取的文本
};

#define LOG(format, ...)                           \
do                                                 \
{                                                  \
    time_t timeSec;                                \
    time(&timeSec);                                \
    struct tm tmRst;                               \
    localtime_r(&timeSec, &tmRst);                 \
    char strTime[10];                              \
    strftime(strTime, sizeof(strTime), "%H:%M:%S", &tmRst);              \
    fprintf(stdout, "[shm-utils] %s " format "\n",strTime, ##__VA_ARGS__);   \
    FILE* fp;   \
    fp = fopen("/data/disTestSuiteLog" , "a+"); \
    fprintf(fp, "[shm-utils] %s " format "\n",strTime, ##__VA_ARGS__);   \
    fclose(fp); \
} while(0)

int createShm(int key);
int disconnectShm(void);
int writeCodeDataToShm(int code, char* buf);
int waitDataWithCode(char* code, char* data);
int writeDataToShm(char* buf);
int deleteShm(void);
char* Int2String(int num,char *str);
void initShm(void);
int readDataFromShm(char* buf);


#endif
