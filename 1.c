#include<stdio.h>
#include<string.h>
char hz[11][5]={"��","һ","��","��","��","��","��","��","��","��","ʮ"}; //����һ����������
int hzs(char a[]){
    int i;
    for(i=0;i<11;i++){
        if(strcmp(hz[i],a)==0){//ͨ��strcmp�����Ƚ�
            return i;
        }
    }
}
int num(char a[]){
    char b[10],c[10];
    if(strlen(a)==2){//һ������ռ2bite �˴����ж�����һ�����ֵ����
        return hzs(a); 
    }
    else if(strlen(a)==4){
        b[0]=a[2];
        b[1]=a[3];
        b[2]='\0';      
            if(hzs(b)!=10) return 10+hzs(b);//�˴����ж������� Ϊʮ����λ����
            else{
                b[0]=a[0];
                b[1]=a[1];
                b[2]='\0';
                return 10*hzs(b);//�˴����ж�����β Ϊʮ�ĺ���
            }
    
    }
    else if(strlen(a)==6){
        b[0]=a[4];
        b[1]=a[5];
        b[2]='\0';
        c[0]=a[0];
        c[1]=a[1];
        c[2]='\0';
        return hzs(b)+hzs(c)*10;//��Ӧ����ʮ�������͵�����
    }
}
int judge(int n,char a[],char b[]){
    int sum1;
    sum1=num(b);
    if(strcmp(a,"����")==0) 
		return n+sum1;
    else if(strcmp(a,"����")==0)
		return n-sum1;
}
int main(){
    int i,sum;
    char a[100],b[100],c[100],d[100];
    scanf("%s",a);
    if(!strcmp(a,"����")){
        scanf("%s %s %s",a,b,c);
    }
    else{
        printf("�����ʽ����\n"); 
        return 0;
    }
    sum=num(c);//���Ե㣺printf��"%d\n",sum��;
    while(scanf("%s %s",d,b)!=EOF){
        if(strcmp(d,"����")){ //��������������ظ����ò鿴����
            scanf("%s",c);
            if(!strcmp(a,d)){
                sum=judge(sum,b,c);//���Ե㣺printf��"%d\n",sum��;        
                if(sum>=99||sum<=0){
                    printf("���������ɷ�Χ\n");
                    return 0;
                }
            }
            else {printf("������ƥ��\n");
                return 0;
            } 
        }
        else{
            if(sum>=0&&sum<=10){
                printf("%s\n",hz[sum]);
            }
            else {
                if(sum%10==0){
                    printf("%sʮ\n",hz[sum/10]);
                }
                else if(sum<=19){
                    printf("ʮ%s\n",hz[sum%10]);
                }
                else {
                    printf("%sʮ%s\n",hz[sum/10],hz[sum%10]);
                }
            }   
        }
    }
return 0;       
}