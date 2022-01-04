#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#define MAX 1000
using namespace std;
int Book_Count=0,Disk_Count=0,Pic_Count=0;
class Lib
{
public:
	void Item_Add()
	{
		cout<<"���:";
		cin>>Number;
		cout<<"����:";
		cin>>Title;
		cout<<"����:";
		cin>>Artist;
		cout<<"����:";
		cin>>Level;
	}
	void Item_Display()
	{
		cout<<"���:"<<Number<<"    ����:"<<Title<<"    ����:"<<Artist<<"    ����:"<<Level;
	}
	long Number;
	string Title;
	string Artist;
	string Level;
};
class Book:public Lib
{
public:
	void Book_Add()
	{
		Lib::Item_Add();
		cout<<"������:";
		cin>>Publish;
		cout<<"ISBN:";
		cin>>ISBN;
		cout<<"ҳ��:";
		cin>>Page_Num; 
	}
	void Book_Display()
	{
		Lib::Item_Display();
		cout<<"    ������:"<<Publish<<"    ISBN:"<<ISBN<<"    ҳ��:"<<Page_Num<<endl; 
	}
	string Publish;
	string ISBN;
	int Page_Num;
};
class Disk:public Lib
{
public:
	void Disk_Add()
	{
		Lib::Item_Add();
		cout<<"��Ʒ������:";
		cin>>Producer;
		cout<<"��Ʒ���:";
		cin>>Date;
		cout<<"��Ƶʱ��:";
		cin>>Time;
	}
	void Disk_Display()
	{
		Lib::Item_Display();
		cout<<"    ��Ʒ������:"<<Producer<<"    ��Ʒ���:"<<Date<<"    ��Ƶʱ��:"<<Time<<endl;
	}
	string Producer;
	string Date;
	string Time;
};
class Pic:public Lib
{
public:
	void Pic_Add()
	{
		Lib::Item_Add();
		cout<<"��Ʒ����:";
		cin>>Country; 
		cout<<"��Ʒ�ĳ�:";
		cin>>Length;
		cout<<"��Ʒ�Ŀ�:";
		cin>>Width; 
	}
	void Pic_Display()
	{
		Lib::Item_Display();
		cout<<"    ��Ʒ����:"<<Country<<"    ��Ʒ�ĳ�:"<<Length<<"cm"<<"    ��Ʒ�Ŀ�:"<<Width<<"cm"<<endl;
	}
	string Country;
	int Length;
	int Width;
};
Book book[MAX];
Disk disk[MAX];
Pic pic[MAX];
void SHOW_MENU()
{
	cout<<"============================================================="<<endl;
    cout<<"         1.�����Ʒ      2.��ѯ��Ʒ      3.��ʾ��Ʒ��          "<<endl;
    cout<<"         4.�༭��Ʒ      5.ɾ����Ʒ      6.ͳ����Ϣ            "<<endl;
    cout<<"         7.��Ʒ����      8.��ȡ��Ʒ      9.��ȫ�˳�            "<<endl;
	cout<<"============================================================="<<endl<<endl;
}
void Item_Add()
{
	cout<<"==================================================="<<endl;
    cout<<"                       �����Ʒ                   "<<endl;
    cout<<"      1.���ͼ��    2.�����Ƶ����    3.���ͼ��    "<<endl;
	cout<<"==================================================="<<endl<<endl;
	int n;
    fflush(stdin);
	cin>>n;
	switch(n)
	{
		case 1:book[Book_Count++].Book_Add();break;
		case 2:disk[Disk_Count++].Disk_Add();break;
		case 3:pic[Pic_Count++].Pic_Add();break;
		default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.������� 2.���ز˵�"<<endl;
	cout<<"===================="<<endl;
	int x;
	cin>>x;
	switch(x)
	{
		case 1:Item_Add();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"��������!Ĭ�ϻص��˵�!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Search()
{
	int x,n,flag=0;
	long search_num;
	string search_title; 
	cout<<"==================================================="<<endl;
    cout<<"                       ��ѯ��Ʒ                     "<<endl;
    cout<<"     1.�������ѯ    2.����Ų�ѯ    3.������ѯ     "<<endl;
	cout<<"==================================================="<<endl<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		{
			cout<<"�������:";
			cin>>search_title;
			for(int i=0;i<Book_Count;i++)
			if(search_title==book[i].Title) 
			{
				cout<<"��ѯ�������:"<<endl;
				book[i].Book_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Disk_Count;i++)
			if(search_title==disk[i].Title)
			{
				cout<<"��ѯ�������:"<<endl;
				disk[i].Disk_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Pic_Count;i++)
			if(search_title==pic[i].Title)
			{
				cout<<"��ѯ�������:"<<endl;
				pic[i].Pic_Display();
				flag=1;
				break;
			}
			if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ���     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 2:
		{
			cout<<"������:";
			cin>>search_num;
			for(int i=0;i<Book_Count;i++)
			if(search_num==book[i].Number) 
			{
				cout<<"��ѯ�������:"<<endl;
				book[i].Book_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Disk_Count;i++)
			if(search_num==disk[i].Number)
			{
				cout<<"��ѯ�������:"<<endl;
				disk[i].Disk_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Pic_Count;i++)
			if(search_num==pic[i].Number)
			{
				cout<<"��ѯ�������:"<<endl;
				pic[i].Pic_Display();
				flag=1;
				break;
			}
			if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 3:
		{
			int x;
			cout<<"========================================"<<endl;
			cout<<"1.��ѯͼ��    2.��ѯ��Ƶ����    3.��ѯͼ��"<<endl;
			cout<<"========================================"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
				{
					if(Book_Count==0)
					{
						cout<<"===================="<<endl;
						cout<<"    �����û����Ʒ   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else 
					{
						cout<<"=================="<<endl;
						cout<<"������ͼ��������Ϣ"<<endl; 
						for(int i=0;i<Book_Count;i++) book[i].Book_Display();
						cout<<"=================="<<endl<<endl;
					}
					break;
				}
				case 2:
				{
					if(Disk_Count==0) 
					{
						cout<<"===================="<<endl;
						cout<<"    �����û����Ʒ   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else
					{
						cout<<"======================"<<endl;
						cout<<"��������Ƶ����������Ϣ"<<endl;
						for(int i=0;i<Disk_Count;i++) disk[i].Disk_Display();
						cout<<"======================"<<endl<<endl;
					}
					break;
				}
				case 3:
				{
					if(Pic_Count==0)
					{
						cout<<"===================="<<endl;
						cout<<"    �����û����Ʒ   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else
					{
						cout<<"=================="<<endl;
						cout<<"������ͼ��������Ϣ"<<endl; 
						for(int i=0;i<Pic_Count;i++) pic[i].Pic_Display();
						cout<<"=================="<<endl<<endl;
					}
					break;
				}
				default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
			} 
		}
		default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.�������� 2.���ز˵�"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Search();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"��������!Ĭ�ϻص��˵�!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Show()
{
	int x,n;
	cout<<"========================================================="<<endl;
    cout<<"                        ��ʾ��Ʒ��                        "<<endl;
    cout<<"      1.��ʾͼ���    2.��ʾ��Ƶ���̿�    3.��ʾͼ����      "<<endl;
	cout<<"========================================================="<<endl<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		{
			if(Book_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ�����û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
			else
			{
				cout<<"===================="<<endl;
				cout<<"ͼ����е���Ʒ������ʾ"<<endl;
				for(int i=0;i<Book_Count;i++) book[i].Book_Display();
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 2:
		{
			if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  ��Ƶ���̿���û��Ʒ  "<<endl;
				cout<<"===================="<<endl<<endl;
			}
			else
			{
				cout<<"========================"<<endl;
				cout<<"��Ƶ���̿��е���Ʒ������ʾ"<<endl;
				for(int i=0;i<Disk_Count;i++) disk[i].Disk_Display();
				cout<<"========================"<<endl<<endl;
			}
            break;
		}
		case 3:
		{
			if(Pic_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ������û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
			}
			else
			{
				cout<<"===================="<<endl;
				cout<<"ͼ�����е���Ʒ������ʾ"<<endl;
				for(int i=0;i<Pic_Count;i++) pic[i].Pic_Display();
				cout<<"===================="<<endl;
			}
            break;
		}
		default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.������ʾ 2.���ز˵�"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Show();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"��������!Ĭ�ϻص��˵�!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Edit()
{
	int x,n,flag=0;
	cout<<"==================================================="<<endl;
    cout<<"                       �༭��Ʒ                     "<<endl;
    cout<<"      1.�༭ͼ��    2.�༭��Ƶ����    3.�༭ͼ��      "<<endl;
	cout<<"==================================================="<<endl<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            if(Book_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ�����û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"�༭ͼ��,����ͼ��ı��:";
            cin>>edit_num;
            for(int i=0;i<Book_Count;i++)
            if(edit_num==book[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"  �ҵ�ͼ��,�����޸�  "<<endl;
				cout<<"===================="<<endl<<endl;
                book[i].Book_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 2:
        {
            if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  ��Ƶ���̿���û��Ʒ  "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"�༭��Ƶ����,������Ƶ���̵ı��:";
            cin>>edit_num;
            for(int i=0;i<Disk_Count;i++)
            if(edit_num==disk[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"�ҵ���Ƶ����,�����޸�"<<endl;
				cout<<"===================="<<endl<<endl;
                disk[i].Disk_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 3:
        {
            if(Pic_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ������û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"�༭ͼ��,����ͼ���ı��:";
            cin>>edit_num;
            for(int i=0;i<Pic_Count;i++)
            if(edit_num==pic[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"  �ҵ�ͼ��,�����޸�  "<<endl;
				cout<<"===================="<<endl<<endl;
                pic[i].Pic_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
		default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
    }
	cout<<"===================="<<endl;
	cout<<"1.�����༭ 2.���ز˵�"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Edit();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"��������!Ĭ�ϻص��˵�!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Delete()
{
    int x,n,flag=0;
	cout<<"==================================================="<<endl;
    cout<<"                       ɾ����Ʒ                     "<<endl;
    cout<<"      1.ɾ��ͼ��    2.ɾ����Ƶ����    3.ɾ��ͼ��      "<<endl;
	cout<<"==================================================="<<endl<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            if(Book_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ�����û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"����Ҫɾ����ͼ��ı��:";
            cin>>delete_num;
            for(int i=0;i<Book_Count;i++)
            if(delete_num==book[i].Number)
            {
				flag=1;
				cout<<"===================="<<endl;
                cout<<"�ҵ�ͼ��,�Ƿ����ɾ��?"<<endl;
				cout<<"  ��(Y)/��(�����ַ�) "<<endl;
				cout<<"===================="<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Book_Count;j++)
                	{
                   		book[j].Number=book[j+1].Number;
                    	book[j].Title=book[j+1].Title;
                    	book[j].Artist=book[j+1].Artist;
                    	book[j].Level=book[j+1].Level;
                    	book[j].Publish=book[j+1].Publish;
                    	book[j].ISBN=book[j+1].ISBN;
                    	book[j].Page_Num=book[j+1].Page_Num;
                	}
               		Book_Count--;
					cout<<"===================="<<endl;
					cout<<"      ɾ���ɹ�       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      ȡ��ɾ��       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 2:
        {
            if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  ��Ƶ���̿���û��Ʒ  "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"����Ҫɾ������Ƶ���̵ı��:";
            cin>>delete_num;
            for(int i=0;i<Disk_Count;i++)
            if(delete_num==disk[i].Number)
            {
				flag=1;
				cout<<"========================"<<endl;
                cout<<"�ҵ���Ƶ����,�Ƿ����ɾ��?"<<endl;
				cout<<"    ��(Y)/��(�����ַ�)   "<<endl;
				cout<<"========================"<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Disk_Count;j++)
                	{
                    	disk[j].Number=disk[j+1].Number;
                    	disk[j].Title=disk[j+1].Title;
                    	disk[j].Artist=disk[j+1].Artist;
                    	disk[j].Level=disk[j+1].Level;
                    	disk[j].Producer=disk[j+1].Producer;
                    	disk[j].Date=disk[j+1].Date;
                    	disk[j].Time=disk[j+1].Time;
                	}
                	Disk_Count--;
					cout<<"===================="<<endl;
					cout<<"      ɾ���ɹ�       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      ȡ��ɾ��       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0) 
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 3:
        {
            if(Pic_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    ͼ������û��Ʒ   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"����Ҫɾ����ͼ���ı��:";
            cin>>delete_num;
            for(int i=0;i<Pic_Count;i++)
            if(delete_num==pic[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"�ҵ�ͼ��,�Ƿ����ɾ��?"<<endl;
				cout<<"  ��(Y)/��(�����ַ�) "<<endl;
				cout<<"===================="<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Pic_Count;j++)
                	{
                    	pic[j].Number=pic[j+1].Number;
                    	pic[j].Title=pic[j+1].Title;
                    	pic[j].Artist=pic[j+1].Artist;
                    	pic[j].Level=pic[j+1].Level;
                    	pic[j].Country=pic[j+1].Country;
                    	pic[j].Length=pic[j+1].Length;
                    	pic[j].Width=pic[j+1].Width;
                	}
                	Pic_Count--;
					cout<<"===================="<<endl;
					cout<<"      ɾ���ɹ�       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      ȡ��ɾ��       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      �����ڱ��     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
		default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
    }
	cout<<"===================="<<endl;
	cout<<"1.����ɾ�� 2.���ز˵�"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Delete();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"��������!Ĭ�ϻص��˵�!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Sum()
{
	cout<<"============================================================="<<endl;
    cout<<"��Ʒ��������Ʒ��Ϊ:"<<(Book_Count+Disk_Count+Pic_Count)<<endl;
    cout<<"ͼ������Ϊ:"<<Book_Count<<"    ��Ƶ��������Ϊ:"<<Disk_Count<<"    ͼ������Ϊ:"<<Pic_Count<<endl;
	cout<<"============================================================="<<endl<<endl;
}
void Item_Save()
{
	ofstream book_save,disk_save,pic_save;
	book_save.open("Book.txt");
	disk_save.open("Disk.txt");
	pic_save.open("Pic.txt");
	book_save<<"ͼ���:"<<endl;
	disk_save<<"��Ƶ���̿�:"<<endl;
	pic_save<<"ͼ����:"<<endl;
	for(int i=0;i<Book_Count-1;i++)
	book_save<<book[i].Number<<"\t"<<book[i].Title<<"\t"<<book[i].Artist<<"\t"<<book[i].Level<<"\t"<<book[i].Publish<<"\t"<<book[i].ISBN<<"\t"<<book[i].Page_Num<<endl;
	book_save<<book[Book_Count-1].Number<<"\t"<<book[Book_Count-1].Title<<"\t"<<book[Book_Count-1].Artist<<"\t"<<book[Book_Count-1].Level<<"\t"<<book[Book_Count-1].Publish<<"\t"<<book[Book_Count-1].ISBN<<"\t"<<book[Book_Count-1].Page_Num;
	for(int i=0;i<Disk_Count-1;i++)
	disk_save<<disk[i].Number<<"\t"<<disk[i].Title<<"\t"<<disk[i].Artist<<"\t"<<disk[i].Level<<"\t"<<disk[i].Producer<<"\t"<<disk[i].Date<<"\t"<<disk[i].Time<<endl;
	disk_save<<disk[Disk_Count-1].Number<<"\t"<<disk[Disk_Count-1].Title<<"\t"<<disk[Disk_Count-1].Artist<<"\t"<<disk[Disk_Count-1].Level<<"\t"<<disk[Disk_Count-1].Producer<<"\t"<<disk[Disk_Count-1].Date<<"\t"<<disk[Disk_Count-1].Time;
	for(int i=0;i<Pic_Count-1;i++)
	pic_save<<pic[i].Number<<"\t"<<pic[i].Title<<"\t"<<pic[i].Artist<<"\t"<<pic[i].Level<<"\t"<<pic[i].Country<<"\t"<<pic[i].Length<<"\t"<<pic[i].Width<<endl;
	pic_save<<pic[Pic_Count-1].Number<<"\t"<<pic[Pic_Count-1].Title<<"\t"<<pic[Pic_Count-1].Artist<<"\t"<<pic[Pic_Count-1].Level<<"\t"<<pic[Pic_Count-1].Country<<"\t"<<pic[Pic_Count-1].Length<<"\t"<<pic[Pic_Count-1].Width;
	book_save.close();
	disk_save.close();
	pic_save.close();
	cout<<"==================="<<endl;
	cout<<"      �������      "<<endl;
	cout<<"==================="<<endl<<endl;
}
void Item_Read()
{
	ifstream book_read,disk_read,pic_read;
	book_read.open("Book.txt",ios::in);
	disk_read.open("Disk.txt",ios::in);
	pic_read.open("Pic.txt",ios::in);
	Book_Count=Disk_Count=Pic_Count=0;
	string str;
	while(getline(book_read,str))
	{
		book_read>>book[Book_Count].Number>>book[Book_Count].Title>>book[Book_Count].Artist>>book[Book_Count].Level>>book[Book_Count].Publish>>book[Book_Count].ISBN>>book[Book_Count].Page_Num;
		Book_Count++;
	}
	while(getline(disk_read,str))
	{
		disk_read>>disk[Disk_Count].Number>>disk[Disk_Count].Title>>disk[Disk_Count].Artist>>disk[Disk_Count].Level>>disk[Disk_Count].Producer>>disk[Disk_Count].Date>>disk[Disk_Count].Time;
		Disk_Count++;
	}
	while(getline(pic_read,str))
	{
		pic_read>>pic[Pic_Count].Number>>pic[Pic_Count].Title>>pic[Pic_Count].Artist>>pic[Pic_Count].Level>>pic[Pic_Count].Country>>pic[Pic_Count].Length>>pic[Pic_Count].Width;
		Pic_Count++;
	}
	book_read.close();
	disk_read.close();
	pic_read.close();
	cout<<"==================="<<endl;
	cout<<"      ��ȡ���      "<<endl;
	cout<<"==================="<<endl<<endl;
}
int main()
{
	cout<<"##################################"<<endl;
    cout<<"       ��ӭ����ý������ϵͳ      "<<endl;
	cout<<"     ���빦��ǰ��Ӧ��Ž��в���    "<<endl;
	cout<<"##################################"<<endl<<endl;
	SHOW_MENU();
    while(1)
    {
        int n;
        cin>>n;
        switch(n)
        {
            case 1:Item_Add();break;
            case 2:Item_Search();break;
            case 3:Item_Show();break;
            case 4:Item_Edit();break;
            case 5:Item_Delete();break;
            case 6:Item_Sum();break;
			case 7:Item_Save();break;
			case 8:Item_Read();break;
			case 9:Item_Save();return 0;
			default:cout<<"��������!��ֹ�˴β���!"<<endl;break;
        }
    }
}
