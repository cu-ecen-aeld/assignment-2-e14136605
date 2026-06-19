#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // 開啟 syslog，設定 facility 為 LOG_USER
    openlog("writer", 0, LOG_USER);

    // 檢查參數數量是否正確 (程式名稱 + 檔案路徑 + 寫入字串 = 3)
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        printf("Usage: %s <file> <string>\n", argv[0]);
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // 紀錄準備寫入的動作 (LOG_DEBUG 層級)
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // 嘗試開啟檔案 (以寫入模式 "w")
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        // 如果檔案開啟失敗，紀錄錯誤原因 (LOG_ERR 層級)
        syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
        return 1;
    }

    // 將字串寫入檔案
    fprintf(file, "%s", writestr);
    
    // 關閉檔案與 syslog
    fclose(file);
    closelog();

    return 0; // 成功結束
}
