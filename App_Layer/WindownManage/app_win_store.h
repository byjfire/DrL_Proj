#ifndef APP_WIN_STORE_H
#define APP_WIN_STORE_H

#include "app_win_common.h"
#include "app_win_process.h"

eAppWinHandle App_StoreWin_Init(void);
eAppWinHandle App_StoreWin_Cb(eAppWinHandle WinHandle, App_Win_Msg_T message);


#endif

