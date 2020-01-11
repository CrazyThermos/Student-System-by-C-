#include<iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio> 
using namespace std;
string str1;//全局变量 
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
    int MAX;//设置最大人数 
    int StuMount;//当前学生人数 
	string name;//专业名称 
	Student stu[100]; //学生 
    public:
    void InitSystem(int MAXX,string namee){
      	MAX=MAXX;
      	name=namee;
		StuMount=0;
    }
    void setSys(int n,string name1){//修改系统信息 
  		MAX=n;
  		name=name1; 
  		
    }
    void DoEntering(string name1,int clas1,long ID1,double score1)  //输入 
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
    		cout<<"学生数量已满"<<endl;
    
    }
    void GetStuMount(){//获取学生数量 
    	cout<<"学生数量:"<<StuMount<<"人"<<endl; 
    }
    void GetName(){
    str1=name;
	} 
    void GetMojar(string n){//获取专业名称 
	n=name;
	}
    void GetAll(){//输出该系统的学生信息 
    	for(int i=0;i<StuMount;i++)
			cout<<"姓名:"+stu[i].name<<endl
			<<"专业:"<<stu[i].major<<endl
			<<"班级:"<<stu[i].clas<<"班"<<endl
			<<"学号:"<<stu[i].ID<<endl
			<<"绩点:"<<stu[i].score<<endl
			<<endl;
    }
    void SetStu(string name1,int clas1,long ID1,double score1){//修改学生所有信息 
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
		cout<<"未找到"<<endl; 
    }
    void Delete(string n){//删除指定的学生信息 
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
		cout<<"未找到"<<endl; 
    }
    void Find(long n){//查找学生信息 
  		for(int i=0;i<StuMount;i++){
  			if(n==stu[i].ID){
			 cout<<"姓名:"+stu[i].name<<endl
			<<"专业:"<<stu[i].major<<endl
			<<"班级:"<<stu[i].clas<<"班"<<endl
			<<"学号:"<<stu[i].ID<<endl
			<<"绩点:"<<stu[i].score<<endl
			<<endl;
			  break;
			}
		}
    }
    void Prov(){//按绩点进行排序 
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
	void reflesh(){	//将文件进行存储和刷新 
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
	int read(){//读取文件内容 
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
			cout<<"未发现数据"<<endl; 
			return 0;
		}
		fclose(fp);

	
	} 
};


int main(){
    int n=1;
    int MAX;//设置最大人数 
	string name;//专业名称 
    StudentSystem Com;
    int p; 
    p=Com.read();
	if(p==0){//判断是否需要初始化 
	
    cout<<"初始化系统"<<endl;
    cout<<"请输入最大学生数量"<<endl;
        cin>>MAX;
    cout<<"请输入本系统所属专业"<<endl;
    	cin>>name; 
       Com.InitSystem(MAX,name);
   }
   else{
   cout<<"已经检测到数据,进入系统"<<endl; 
    Com.GetName();
    name=str1;
	   } 

    while(1)
    {
        cout <<"-----------------------------------------------"+name+"专业信息管理系统"+"-----------------------------------------------\n\n"
        <<"0:\t\t退出\n\n"
        <<"1:\t\t加入学生信息\n\n"
        <<"2:\t\t修改学生信息\n\n"
        <<"3:\t\t删除学生信息\n\n"
        <<"4:\t\t学号查找学生信息\n\n"
		<<"5:\t\t输出学生信息\n\n" 
		<<"6:\t\t按绩点排序\n\n"
		<<"-----------------------------------------------"+name+"专业信息管理系统"+"-----------------------------------------------\n\n";
        Com.GetStuMount();		
		int choice=-1;
		cout<<"请选择:\n\n";
        cin>>choice;
        if(choice==1){
        	int n=0;
        	cout<<"输入你想要输入的学生个数";
        	cin>>n;	
		
        for(int i=0;i<n;i++){
        	string name;
			int clas;
			long ID;
			double score;
          cout<<"请输入第"<<i+1<<"个学生信息"<<endl; 
          cout<<"姓名"<<endl;
		  cin>>name;
		  cout<<"班级"<<endl;
		  cin>>clas;
		  cout<<"学号"<<endl;
		  cin>>ID;
		  cout<<"绩点"<<endl;
		  cin>>score; 	
		  Com.DoEntering(name,clas,ID,score);
		
    
		  }
	
	
        }
        else if(choice==2){
        	string name;
			int clas;
			long ID;
			double score;
        cout<<"请输入修改的学生姓名"<<endl ;
       	 cout<<"姓名"<<endl;
		  cin>>name;
		  cout<<"请输入要修改的内容"<<endl ;
		  cout<<"班级"<<endl;
		  cin>>clas;
		  cout<<"学号"<<endl;
		  cin>>ID;
		  cout<<"绩点"<<endl;
		  cin>>score; 	
          Com.SetStu(name,clas,ID,score); 
    	}
        else if(choice==3){
        	string name;
      	cout<<"请输入删除的学生姓名"<<endl ;
       	 cout<<"姓名"<<endl;
       	  cin>>name;
           Com.Delete(name);
           cout<<"删除完毕"<<endl; 
       	}
       	else if(choice==4){
        	long ID;
        		cout<<"请输入查找的学生学号"<<endl ;
       	  cout<<"学号"<<endl;
       	  cin>>ID;
       	  Com.Find(ID); 
       	}
       	else if(choice==5){
       	Com.GetAll();
	   	} 
	   	else if(choice==6){
	   	Com.Prov();
	   	cout<<"排序完毕"<<endl ;
		}
    	else if(choice==0){
		
        break;
    	}
		else{
			cout<<"ERROR！！！请输入正确的数字"<<endl;
		}	
		  
		Com.reflesh();//刷新文件 
		
	} 
        
        return 0;
}
