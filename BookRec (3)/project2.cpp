#include<iostream>
#include<cmath>
#include <fstream>
#include <conio.h>
#include<string>
#include <sstream>
using namespace std;
string genres[16] = {"Young Adult","Novel","SciFi","Dystopia","Magic","Adventure","Politics","Romance","Gothic","Historical","Supernatural","Action","Thriller","War","Holocaust","Fantasy"};
class hashNode{
public:
	string genre;
	string title;
	string author;
	double rating;
	hashNode* next;
	hashNode(string t,string a,double r, string g){
		for(int i=0;i<4;i++){
			genre[i]=g[i];
		}
		genre=g; 
		title=t; author=a; rating=r;
		next=NULL;
	}
};

class hashTable{
public:
	hashNode** ht;
	hashTable(){
		ht = new hashNode*[16];
		for(int i=0;i<16;i++){
			ht[i]=NULL;
		}
	}
	int hash(string g){
		int code=0;
		int id=0;
//		for(int i=0;i<g.length();i++){
//			code += g[i];
//		}
		for(int i=0;i<16;i++){
			if(genres[i]==g){
				id = i;
				break;
			}
		}
		code=code+id;
		return code%16;
	}
	insert(string t, string a, double r,string g[4]){
		for(int i=0; i<4; i++){
			int hash_v = hash(g[i]);
		hashNode* prev=NULL;
		hashNode* entry = ht[hash_v];
		while(entry != NULL){
			prev = entry;
			entry=entry->next;
		}
		if(entry==NULL){
			entry = new hashNode(t,a,r,g[i]);
			if(prev==NULL){
				ht[hash_v] = entry;
			}else{
				prev->next = entry;
			}
		}else{
			entry->genre=g[i];
			entry->title=t;
			entry->author=a;
			entry->rating=r;
		}
		}

		
	}
	int search(string k){
		int hash_v = hash(k);
		hashNode* entry = ht[hash_v];
		bool flag = false;
		while(entry != NULL){
			if(entry->genre == k){
				cout << entry->title<< endl;
				flag=true;
			}
			entry=entry->next;
		}
		if(flag==false){
			cout<<"Not found\n";
			return -1;
		}
	}
	int search(string k1, string k2){
		int hash_v1 = hash(k1);
		int hash_v2 = hash(k2);
		hashNode* entry1 = ht[hash_v1];
		bool flag = false;
		while(entry1 != NULL){
			if(entry1->genre == k1){
				string s = entry1->title;
				hashNode* entry2 = ht[hash_v2];
				while(entry2 != NULL){
					if(entry2->title == s){
						cout<<entry2->title<<endl;
						flag=true;
						break;
					}
					entry2=entry2->next;
				}
			}
			entry1=entry1->next;
		}
		if(flag==false){
			cout<<"Not found\n";
			return -1;
		}
	}
	int search(string k1, string k2,string k3){
		int hash_v1 = hash(k1);
		int hash_v2 = hash(k2);
		int hash_v3 = hash(k3);
		hashNode* entry1 = ht[hash_v1];
		bool flag = false;
		while(entry1 != NULL){
			if(entry1->genre == k1){
				string s = entry1->title;
				hashNode* entry2 = ht[hash_v2];
				while(entry2 != NULL){
					if(entry2->title == s){
						hashNode* entry3 = ht[hash_v3];
						while(entry3 != NULL){
							if(entry3->title == s){
								cout<<entry3->title<<endl;
								flag=true;
								break;
							}
							entry3=entry3->next;
						}
					}
					entry2=entry2->next;
				}
			}
			entry1=entry1->next;
		}
		if(flag==false){
			cout<<"Not found\n";
			return -1;
		}
	}
	int search(string k1, string k2,string k3,string k4){
		int hash_v1 = hash(k1);
		int hash_v2 = hash(k2);
		int hash_v3 = hash(k3);
		int hash_v4 = hash(k4);
		hashNode* entry1 = ht[hash_v1];
		bool flag = false;
		while(entry1 != NULL){
			if(entry1->genre == k1){
				string s = entry1->title;
				hashNode* entry2 = ht[hash_v2];
				while(entry2 != NULL){
					if(entry2->title == s){
						hashNode* entry3 = ht[hash_v3];
						while(entry3 != NULL){
							if(entry3->title == s){
								hashNode* entry4 = ht[hash_v4];
								while(entry4 != NULL){
									if(entry4->title == s){
										cout<<entry3->title<<endl;
										flag=true;
										break;
									}
									entry4 = entry4->next;
								}

							}
							entry3=entry3->next;
						}
					}
					entry2=entry2->next;
				}
			}
			entry1=entry1->next;
		}
		if(flag==false){
			cout<<"Not found\n";
			return -1;
		}
	}
//	Delete(string k){
//		int hash_v = hash(k);
//		hashNode* prev = NULL;
//		hashNode* entry = ht[hash_v];
//		if(entry == NULL && entry->pass != k){
//			cout << "Value doesn't exist\n";
//		}
//		while( entry->next != NULL){
//			prev=entry;
//			entry=entry->next;
//		}
//		if(prev != NULL){
//			prev->next = entry->next;
//		}
//		delete entry;
//		cout<<"value deleted\n";
//	}
	Display(){
		//cout<< "DISPLAY RECORD\nGenre		Title				Author		Rating\n";
		//string s="Tragedy";
		for(int i=0;i<16;i++){
			int hash_v = hash(genres[i]);
			hashNode* entry = ht[hash_v];
			//int hash_v = hash(2,s);
			//cout<< &ht[i] <<endl;
			//cout << ht[i]<<endl;
			//hashNode* entry = ht[hash_v];
			//cout<<entry->title<<endl;
			//cout<<"hi\n";
			while(entry != NULL){
				//cout<<"hi\n";
				cout << entry->title;
				entry=entry->next;
			}
			cout<<endl<<endl<<endl;
		}
	}
	sort(){
		string t; string a; double r; string g;
		for(int i=0;i<16;i++){	
			int c=0;
			int hash_v = hash(genres[i]);
			hashNode* entry = ht[hash_v];
				while(entry != NULL){
					c++;
					entry=entry->next;
				}
				for(int i=0;i<c-1;i++){
					entry = ht[hash_v];
					for(int i=0;i<c-1;i++){
						if(entry->rating < entry->next->rating){
				//cout<<"hi\n";
				//hashNode* temp;
				t = entry->title; a=entry->author; r = entry->rating;
//				for(int i=0;i<4;i++){
					g = entry->genre;
//				}
				entry->title = entry->next->title; entry->author=entry->next->author; entry->rating=entry->next->rating;
//				for(int i=0;i<4;i++){
					entry->genre = entry->next->genre;
//				}
				entry->next->title = t;   entry->next->author = a; entry->next->rating = r;
//				for(int i=0;i<4;i++){
					entry->next->genre = g;
//				}
				}
				entry=entry->next;
				}
				
				}
		}
}
//	update(string k){
//		int hash_v = hash(k);
//		hashNode* entry = ht[hash_v];
//		bool flag = false;
//		if(entry != NULL && entry->pass == k){
//			cout<<"Enter name: ";
//			cin>>entry->name;
//			cout<< "Details update:\n	PASS		Name\n";
//			cout <<"\t" <<entry->pass << "\t\t" << entry->name << endl;
//			flag=true;
//		}
//		if(flag==false){
//			cout<<"Not found\n";
//			return -1;
//		}
//	}
};

main(){
	hashTable obj;
	stringstream ss;
	ifstream inFile;
	string title;
	string rating;
	string author;
	string genre[4];
	string id;
inFile.open("sampleData.csv");
if (inFile.is_open()) {
    cout << "File has been opened" << endl;
}
else {
    cout << "NO FILE HAS BEEN OPENED" << endl;
}

while (!inFile.eof()) {
    getline (inFile, title, ',' );
    //cout << "\nTitle  : " << title;
    getline (inFile, author, ',' );
    //cout << "\nAuthor : " << author;
    getline (inFile, rating, ',');
    //cout << "\nRating : " << rating;
    for(int i=0;i<4;i++){
    	getline (inFile, genre[i], ',' );
    	//cout << "\nGenre : " << genre[i];
	}
    getline (inFile, id, '\n' );
	//cout << "\nGenre  : " << genre;
	//getline (inFile, id, '\n');
	//cout << "\nID     : " << id << "\n";
//	int r;
//	ss << rating;
//	ss>>r;
//	stod(rating);
	
	obj.insert(title,author,stod(rating),genre);
}
inFile.close();
obj.sort();

//	cout<<"How many genres to search for:\n1. One\n2. Two\nEnter choice: ";
//	int c; cin>>c;
	//search()
	
//	obj.insert(1,"Mystery","The girl on the train","Huzefa",3.5);
//	obj.insert(2,"Tragedy","The Kite Runner","Saleh Shamoon",4.5);
//	obj.insert(1,"Mystery","The Kite Runner","Saleh",4.5);
//	obj.insert(3,"Suspense","The girl on the train","Saleh Shamoon",4.5);

	//obj.insert(2,"Tragedy","The Kite Runner2","Saleh",4.5);
	//cout << obj.hash(2,"Tragedy");
	//cout << obj.hash(1,"Mystery");
//	cout<<"Thriller\n";
	//obj.search("Thriller");
//	cout<<"Dystopia\n";
	//obj.search("Historical","Novel","War");
	//obj.Display();
	
}
