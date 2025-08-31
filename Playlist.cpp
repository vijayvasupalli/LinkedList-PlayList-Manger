#include<iostream>
#include<string>
using namespace std;

class Song{
    public:
      string name;
      Song* next;
      Song* prev;
      Song(string n){
        name=n;
        next=prev=NULL;
      }
};

class PlayList{
    private:
      Song* head;
      Song* tail;
      Song* current;
    public:
        PlayList(){
            head=tail=current=NULL;
        }
    
    void addSong(string name){
        Song* newSong=new Song(name);
        if(head==NULL){
            head=tail=current=newSong;
            return;
        }
        else{
            newSong->prev=tail;
            tail->next=newSong;
            tail=newSong;
        }
        cout<<"Song Added At Back:"<<name<<endl;
    }

    void addSongFront(string name){
        Song* newSong=new Song(name);
        if(head==NULL){
            head=tail=current=newSong;
            return;
        }
        else{
            newSong->next=head;
            head->prev=newSong;
            head=newSong;
        }
        cout<<"Song Added At Front:"<<name<<endl;
    }

    void deleteSong(string name){
        Song* temp=head;
        while(temp!=NULL && temp->name!=name){
            temp=temp->next;
        }
        if(temp==tail){
            tail=temp->prev;
        }
        if(temp==head){
            head=temp->next;
        }
        if(temp->next){
            temp->next->prev=temp->prev;
        }
        if(temp->prev){
            temp->prev->next=temp->next;
        }
        if(current==temp){
            if(temp->next){
                current=temp->next;
            }
            else{
                current=head;
            }
        }
        if(!temp){
            cout<<"Song Not Found-(cannot Be Deleted)..."<<endl;
            return;
        }
        cout<<"Song Deleted:"<<temp->name<<endl;
        delete temp;
    }

    void playCurrent(){
        if(!current){
            cout<<"Playlist is EMPTY..."<<endl;
            return;
        }
        else{
            cout<<"Current Song Playing:-->"<<current->name<<endl;
        }
    }
    
    void playNext(){
        if(!current||!current->next){
            cout<<"*No Next Song is There...*"<<endl;
            return;
        }
        else{
            current=current->next;
            cout<<"NEXT song will be..."<<current->name<<endl;
        }
    }

    void playPrev(){
        if(!current||!current->prev){
            cout<<"*No Previous Song left...*"<<endl;
            return;
        }
        else{
            current=current->prev;
            cout<<"Previous Song be..."<<current->name<<endl;
        }
    }

    void displayPlayList(){
        if(!head){
            cout<<"Playlist EMPTY...!"<<endl;
            return ;
        }
        else{
            Song* temp=head;
            int i=1;
            cout<<"------------------"<<endl;
            cout<<"***_______Playlist______***"<<endl;
            while(temp!=NULL){
                cout<<i++<<"."<<temp->name<<endl;
                temp=temp->next;
            }
            cout<<"______________________"<<endl;
        }
    }

};


int main(){
    PlayList music;
    int choice;
    string song;
    do{
        cout<<"_____Playlist Menu_____"<<endl;
        cout<<"1.Add Song(Back)"<<endl;
        cout<<"2.Add Song(Front)"<<endl;
        cout<<"3.Display List"<<endl;
        cout<<"4.Delete a Song"<<endl;
        cout<<"5.Play Current"<<endl;
        cout<<"6.Play Previous"<<endl;
        cout<<"7.Play Next"<<endl;
        cout<<"0.EXIT"<<endl;
        cout<<"Enter Your choice:";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1: cout<<"Enter Song Name:"; 
                    getline(cin,song);
                    music.addSong(song);
                    cout<<"----------"<<endl;
                    break;
            case 2: cout<<"Enter Song Name:";
                    getline(cin,song);
                    music.addSongFront(song);
                    cout<<"----------"<<endl;
                    break;
            case 3: music.displayPlayList();
                    break;
            case 4: cout<<"Enter Song Name To REMOVE:";
                    getline(cin,song);
                    music.deleteSong(song);
                    cout<<"----------"<<endl;
                    break;
            case 5: music.playCurrent();
                    break;
            case 6: music.playPrev();
                    break;
            case 7: music.playNext();
                    break;
            case 0: cout<<"Exit Playlist...."<<endl;
                    break;
            default: cout<<"InValid Choice You Entered !!"<<endl;       

        }
    }while(choice!=0);

     return 0;
    }


