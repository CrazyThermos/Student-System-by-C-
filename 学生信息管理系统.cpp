#include<iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio> 
using namespace std;
string str1;//ȫ�ֱ��� 
class Student
{
public:
	string name;
	string major;
	int clas;
	long ID;
	double score;
};

class StudentSystem 
{   int a=1;
    
    private:
    int MAX;//����������� 
    int StuMount;//��ǰѧ������ 
	string name;//רҵ���� 
	Student stu[100]; //ѧ�� 
    public:
    void InitSystem(int MAXX,string namee){
      	MAX=MAXX;
      	name=namee;
		StuMount=0;
    }
    void setSys(int n,string name1){//�޸�ϵͳ��Ϣ 
  		MAX=n;
  		name=name1; 
  		
    }
    void DoEntering(string name1,int clas1,long ID1,double score1)  //���� 
    {
    	if(StuMount<MAX){
			stu[StuMount].name=name1;
			stu[StuMount].major=name;
			stu[StuMount].clas=clas1;
			stu[StuMount].ID=ID1;
    		stu[StuMount].score=score1;
    		StuMount++;
    	}
		else
    		cout<<"ѧ����������"<<endl;
    
    }
    void GetStuMount(){//��ȡѧ������ 
    	cout<<"ѧ������:"<<StuMount<<"��"<<endl; 
    }
    void GetName(){
    str1=name;
	} 
    void GetMojar(string n){//��ȡרҵ���� 
	n=name;
	}
    void GetAll(){//�����ϵͳ��ѧ����Ϣ 
    	for(int i=0;i<StuMount;i++)
			cout<<"����:"+stu[i].name<<endl
			<<"רҵ:"<<stu[i].major<<endl
			<<"�༶:"<<stu[i].clas<<"��"<<endl
			<<"ѧ��:"<<stu[i].ID<<endl
			<<"����:"<<stu[i].score<<endl
			<<endl;
    }
    void SetStu(string name1,int clas1,long ID1,double score1){//�޸�ѧ��������Ϣ 
   		int k=0;
		for(int i=0;i<StuMount;i++){
   			if(stu[i].name.compare(name1)==0){	
			stu[i].clas=clas1;
			stu[i].ID=ID1;
    		stu[i].score=score1;
   			break;
			}	
			k=i;	
		}
		if(k==StuMount)
		cout<<"δ�ҵ�"<<endl; 
    }
    void Delete(string n){//ɾ��ָ����ѧ����Ϣ 
     	int k=0;
		 for(int i=0;i<StuMount;i++){
     		if(stu[i].name.compare(n)==0){
     			for(int j=i;j<StuMount;j++)
				 stu[j]=stu[j+1];
				StuMount--; 
				break;	 
			}
			k=i;
	 	} 
	 	if(k==StuMount)
		cout<<"δ�ҵ�"<<endl; 
    }
    void Find(long n){//����ѧ����Ϣ 
  		for(int i=0;i<StuMount;i++){
  			if(n==stu[i].ID){
			 cout<<"����:"+stu[i].name<<endl
			<<"רҵ:"<<stu[i].major<<endl
			<<"�༶:"<<stu[i].clas<<"��"<<endl
			<<"ѧ��:"<<stu[i].ID<<endl
			<<"����:"<<stu[i].score<<endl
			<<endl;
			  break;
			}
		}
    }
    void Prov(){//������������� 
    	for(int i=0;i<StuMount-1;i++)
    		for(int j=0;j<StuMount-i-1;j++){
    			if(stu[j].score<stu[j+1].score){
    				Student r;
    				r=stu[j];
    				stu[j]=stu[j+1];
					stu[j+1]=r; 
				}
			}
	}
	void reflesh(){	//���ļ����д洢��ˢ�� 
		ofstream outfile;
		outfile.open("D:\\data.txt");
			outfile<<MAX<<endl
			<<name<<endl
			<<StuMount<<endl
			<<endl; 
			for(int i=0;i<StuMount;i++){ 
    		outfile<<stu[i].name<<endl
			<<stu[i].major<<endl
			<<stu[i].clas<<endl
			<<stu[i].ID<<endl
			<<stu[i].score<<endl
			<<endl;
		}
		outfile.close();
	} 
	int read(){//��ȡ�ļ����� 
		int MAX1;
		char nameS[200];
		int count=0;
		
		char name1[20];
		char major1[20];
		int clas1;
		long ID1;
		double score1;
		char space;
		
		FILE *fp;
		fp=fopen("D:\\data.txt","r");
		if(fp!=NULL){
		 fscanf(fp,"%d%s%d%s",&MAX1,nameS,&count,space);
		 MAX=MAX1;
		 name=nameS; 
			StuMount=count;	 
		for(int i=0;i<count;i++){
			fscanf(fp,"%s%s%d%d%lf%s",name1,major1,&clas1,&ID1,&score1,space);
			stu[i].name=name1;
			stu[i].major=major1;
			stu[i].clas=clas1;
			stu[i].ID=ID1;
			stu[i].score=score1; 

		} 
		return 1;
		}
		else{
			cout<<"δ��������"<<endl; 
			return 0;
		}
		fclose(fp);

	
	} 
};


int main(){
    int n=1;
    int MAX;//����������� 
	string name;//רҵ���� 
    StudentSystem Com;
    int p; 
    p=Com.read();
	if(p==0){//�ж��Ƿ���Ҫ��ʼ�� 
	
    cout<<"��ʼ��ϵͳ"<<endl;
    cout<<"���������ѧ������"<<endl;
        cin>>MAX;
    cout<<"�����뱾ϵͳ����רҵ"<<endl;
    	cin>>name; 
       Com.InitSystem(MAX,name);
   }
   else{
   cout<<"�Ѿ���⵽����,����ϵͳ"<<endl; 
    Com.GetName();
    name=str1;
	   } 

    while(1)
    {
        cout <<"-----------------------------------------------"+name+"רҵ��Ϣ����ϵͳ"+"-----------------------------------------------\n\n"
        <<"0:\t\t�˳�\n\n"
        <<"1:\t\t����ѧ����Ϣ\n\n"
        <<"2:\t\t�޸�ѧ����Ϣ\n\n"
        <<"3:\t\tɾ��ѧ����Ϣ\n\n"
        <<"4:\t\tѧ�Ų���ѧ����Ϣ\n\n"
		<<"5:\t\t���ѧ����Ϣ\n\n" 
		<<"6:\t\t����������\n\n"
		<<"-----------------------------------------------"+name+"רҵ��Ϣ����ϵͳ"+"-----------------------------------------------\n\n";
        Com.GetStuMount();		
		int choice=-1;
		cout<<"��ѡ��:\n\n";
        cin>>choice;
        if(choice==1){
        	int n=0;
        	cout<<"��������Ҫ�����ѧ������";
        	cin>>n;	
		
        for(int i=0;i<n;i++){
        	string name;
			int clas;
			long ID;
			double score;
          cout<<"�������"<<i+1<<"��ѧ����Ϣ"<<endl; 
          cout<<"����"<<endl;
		  cin>>name;
		  cout<<"�༶"<<endl;
		  cin>>clas;
		  cout<<"ѧ��"<<endl;
		  cin>>ID;
		  cout<<"����"<<endl;
		  cin>>score; 	
		  Com.DoEntering(name,clas,ID,score);
		
    
		  }
	
	
        }
        else if(choice==2){
        	string name;
			int clas;
			long ID;
			double score;
        cout<<"�������޸ĵ�ѧ������"<<endl ;
       	 cout<<"����"<<endl;
		  cin>>name;
		  cout<<"������Ҫ�޸ĵ�����"<<endl ;
		  cout<<"�༶"<<endl;
		  cin>>clas;
		  cout<<"ѧ��"<<endl;
		  cin>>ID;
		  cout<<"����"<<endl;
		  cin>>score; 	
          Com.SetStu(name,clas,ID,score); 
    	}
        else if(choice==3){
        	string name;
      	cout<<"������ɾ����ѧ������"<<endl ;
       	 cout<<"����"<<endl;
       	  cin>>name;
           Com.Delete(name);
           cout<<"ɾ�����"<<endl; 
       	}
       	else if(choice==4){
        	long ID;
        		cout<<"��������ҵ�ѧ��ѧ��"<<endl ;
       	  cout<<"ѧ��"<<endl;
       	  cin>>ID;
       	  Com.Find(ID); 
       	}
       	else if(choice==5){
       	Com.GetAll();
	   	} 
	   	else if(choice==6){
	   	Com.Prov();
	   	cout<<"�������"<<endl ;
		}
    	else if(choice==0){
		
        break;
    	}
		else{
			cout<<"ERROR��������������ȷ������"<<endl;
		}	
		  
		Com.reflesh();//ˢ���ļ� 
		
	} 
        
        return 0;
}
