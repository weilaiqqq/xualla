#include<stdio.h>
#include<string.h>
char hz[11][5]={"零","一","二","三","四","五","六","七","八","九","十"}; //定义一个汉字数组
int hzs(char a[]){
    int i;
    for(i=0;i<11;i++){
        if(strcmp(hz[i],a)==0){//通过strcmp函数比较
            return i;
        }
    }
}
int num(char a[]){
    char b[10],c[10];
    if(strlen(a)==2){//一个汉字占2bite 此处是判断输入一个汉字的情况
        return hzs(a); 
    }
    else if(strlen(a)==4){
        b[0]=a[2];
        b[1]=a[3];
        b[2]='\0';      
            if(hzs(b)!=10) return 10+hzs(b);//此处是判断输入首 为十的两位汉字
            else{
                b[0]=a[0];
                b[1]=a[1];
                b[2]='\0';
                return 10*hzs(b);//此处是判断输入尾 为十的汉字
            }
    
    }
    else if(strlen(a)==6){
        b[0]=a[4];
        b[1]=a[5];
        b[2]='\0';
        c[0]=a[0];
        c[1]=a[1];
        c[2]='\0';
        return hzs(b)+hzs(c)*10;//对应“几十几”类型的数字
    }
}
int judge(int n,char a[],char b[]){
    int sum1;
    sum1=num(b);
    if(strcmp(a,"增加")==0) 
		return n+sum1;
    else if(strcmp(a,"减少")==0)
		return n-sum1;
}
int main(){
    int i,sum;
    char a[100],b[100],c[100],d[100];
    scanf("%s",a);
    if(!strcmp(a,"整数")){
        scanf("%s %s %s",a,b,c);
    }
    else{
        printf("输入格式错误\n"); 
        return 0;
    }
    sum=num(c);//测试点：printf（"%d\n",sum）;
    while(scanf("%s %s",d,b)!=EOF){
        if(strcmp(d,"看看")){ //可在运算过程中重复运用查看功能
            scanf("%s",c);
            if(!strcmp(a,d)){
                sum=judge(sum,b,c);//测试点：printf（"%d\n",sum）;        
                if(sum>=99||sum<=0){
                    printf("超出可容纳范围\n");
                    return 0;
                }
            }
            else {printf("变量不匹配\n");
                return 0;
            } 
        }
        else{
            if(sum>=0&&sum<=10){
                printf("%s\n",hz[sum]);
            }
            else {
                if(sum%10==0){
                    printf("%s十\n",hz[sum/10]);
                }
                else if(sum<=19){
                    printf("十%s\n",hz[sum%10]);
                }
                else {
                    printf("%s十%s\n",hz[sum/10],hz[sum%10]);
                }
            }   
        }
    }
return 0;       
}