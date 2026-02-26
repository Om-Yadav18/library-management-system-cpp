// i am makeing  library management system using OOPs and file handling 
// this system function is adding book , deleting book and serahing book ,see all book detail . 
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Book{
    private :
        int bookId;
        string bookName;
        string authorName;
    public :
    // setter 
    void set_detail(int id , string book_name , string author_name){
        bookId = id;
        bookName = book_name;
        authorName = author_name;
    }
    void show_display(){
        cout<<"Book ID : "<<bookId<<endl;
        cout<<"Book Name : "<<bookName<<endl;
        cout<<"Author name : "<<authorName<<endl;
    }
    int get_book_id(){
        return bookId;
    }
    string get_book_name(){
        return bookName;
    }
    string get_author_name(){
        return authorName;
    }
};
// This is for displaying all the book 
void show_all_book( vector<Book> &book){
    int n = book.size();
    if(book.empty()){
        cout<<"No books available.\n";
        return;
    }
    for( int i=0;i<n;i++){
        book[i].show_display();
    }
}
void search_book(vector<Book> &book){
    int n = book.size();
    cout<<" Search Method : \n";
    cout<<"1. Using ID : \n2. Using Book Name : \n3. Using Author Name :\n";
    int Choice;
    cout<<"Enter your choice : ";
    cin>>Choice;
    bool flag = false;
    switch(Choice){
        case 1:{
            int id;
            cout<<"Enter book ID : ";
            cin>>id;
            cin.ignore();
            for(int i=0;i<n;i++){
                if(id == book[i].get_book_id()){
                    book[i].show_display();
                    flag = true;
                    break;
                }
            }
            if( flag == false){
                cout<<"Wrong id or invaild id.\n";
            }
            break;
        }
        case 2:{
            cout<<"Enter book Name : ";
            string name;
            getline(cin , name);
            flag = false;
            for( int i=0;i<n;i++){
                if( name == book[i].get_book_name()){
                    book[i].show_display();
                    flag = true;
                    break;
                }
            }
            if( flag == false){
                cout<<"please check again the book name .\n";
            }
            break;
        }
        case 3:{
            cout<<"Enter Author name : ";
            string author_name;
            getline( cin , author_name);
            flag = false;
            for( int i=0;i<n;i++){
                if( author_name == book[i].get_author_name()){
                    book[i].show_display();
                    flag = true;
                    break;
                }
            }
            if( flag == false){
                cout<<"please check again the author name .\n";
            }
            break;
        }
        default:
            cout<<"you choose the wronge option .\n";
            break;
    }
}
void rewrite_file(vector<Book> &book){
    ofstream file("data.txt");  // overwrite mode

    for(int i = 0; i < book.size(); i++){
        file << "Book Id : " << book[i].get_book_id() << endl;
        file << "Book Name : " << book[i].get_book_name() << endl;
        file << "Author name : " << book[i].get_author_name() << endl;
    }
}
void delete_book(int id , vector<Book> &book){
    int n = book.size();
    bool flag = false;
    for(int i=0;i<n;i++){
        if( id == book[i].get_book_id()){
            book.erase(book.begin() + i);
            rewrite_file(book);
            cout<<"Book id deleted \n";
            flag = true;
            break;
        }
    }
    if( flag == false){
        cout<<"wrong ID . check again id .\n";
    }
}
void add_book(vector<Book> &book){
    ofstream file("data.txt" , ios :: app);
    int n = book.size();
    int totalbook;
    cout<<"Enter how any book you want to add : ";
    cin>>totalbook;
    cin.ignore();
    for( int i=0;i<totalbook;i++){
        int id;
        string book_name;
        string author_name;
        bool terminate = false;
        while( terminate == false){
            cout<<"Enter book ID : ";
            cin>>id;
            bool flag = false;
            for( int i=0;i<book.size() ; i++){
                if( id == book[i].get_book_id()){
                    flag = true;
                    break;
                }
            }
            if( flag == true){
                cout<<"This book id is already exit . Try again .\n";
            }else{
                terminate = true;
            }
        }
        cin.ignore();
        cout<<"Enter book Name : ";
        getline( cin , book_name);
        cout<<"Enter Author name : ";
        getline(cin , author_name);
        Book temp;
        temp.set_detail(id , book_name , author_name);
        book.push_back(temp);
        file<<temp.get_book_id()<<endl;
        file<<temp.get_book_name()<<endl;
        file<<temp.get_author_name()<<endl;
    }
}
void data_load_to_vector(vector<Book> &book){
    ifstream readfile("data.txt");
    string line;
    string book_name , author_name;
    int book_id;
    while(readfile >> book_id){
        readfile.ignore();
        getline(readfile, book_name);
        getline(readfile, author_name);
        Book temp;
        temp.set_detail(book_id, book_name, author_name);
        book.push_back(temp);
    }
    readfile.close();
}
int main(){
    vector<Book> book;
    data_load_to_vector(book);
    while(true){
        cout<<"Library Menu : \n";
        cout<<"1. Add book\n2. Search Book\n3. show All Book\n4. Delete book\n5. Exit\n";
        int choice;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1 :
                add_book(book);
                break;
            case 2 :
                search_book(book);
                break;
            case 3 :
                show_all_book(book);
                break;
            case 4 :
                int ID;
                cout<<"Enter book id : ";
                cin>>ID;
                delete_book(ID , book);
                break;
            case 5 :
                cout<<"thanks for using Om's library system .";
                return 0;
            default :
                cout<<"Invalid choice !! . check again .";
        }
    }
    return 0;
}
