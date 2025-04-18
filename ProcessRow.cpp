#include <cstring>
bool ProcessRow(int row[],int &Score)     //行处理逻辑，处理一行4格空间
{
    int temp[4]={0};
    int index=0;
    for (int i=0;i<4;i++){
        if (row[i]!=0)
        temp[index++]=row[i];
    }   //合并空格
    bool changed=false;
    for (int i=0;i<3;i++){
        if  (temp[i]!=0 && temp[i] == temp[i+1])
        {
            temp[i]*=2;
            Score+=temp[i];
            temp[i+1]=0;
            changed=true;
            i++;    //循环跳过下一格
        }
    }
    int ResRow[4]={0}; //异地合并，与上述段落可合并写为新函数
    index=0;
    for (int i=0;i<4;i++){
        if (temp[i]!=0)
        ResRow[index++]=temp[i];
    }
    bool moved=memcmp(row,ResRow,sizeof(ResRow))!=0; //比较是否变化，并返回结果
    memcpy(row,ResRow,sizeof(ResRow));
    return moved||changed; //返回变化与否
}