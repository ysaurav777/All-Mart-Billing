#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Billing {
    private:
        string Item;
        int Rate,Quantity;
    public:
        void putItem(string item) {
            Item=item;
        }
        void putRate(int rate) {
            Rate=rate;
        }
        void putQuantity(int quantity) {
            Quantity=quantity;
        }
        string getItem() {
            return Item;
        }
        int getRate() {
            return Rate;
        }
        int getQuantity() {
            return Quantity;
        }
};

void AddItem(Billing B1) {
    while(true) {
        system("cls");
        int ch;
        cout<<"1. Add Item"<<endl;
        cout<<"2. Done"<<endl<<endl;
        cout<<"Please enter you choice: ";
        cin>>ch;
        if(ch==1) {
            system("cls");
            int rate,quantity;
            string name;
            cout<<"Please enter item name: ";
            cin>>name;
            cout<<"Please enter item rate: ";
            cin>>rate;
            cout<<"Please enter item quantity: ";
            cin>>quantity;
            B1.putItem(name);
            B1.putRate(rate);
            B1.putQuantity(quantity);
            ofstream out;
            out.open("D:/Bill.txt",ios::app);
            if(!out) {
                cout<<"Error occured with the file"<<endl;
            }
            else {
                out<<B1.getItem()<<" : "<<B1.getRate()<<" : "<<B1.getQuantity()<<endl<<endl;
                cout<<"Item added is a Success"<<endl;
                cout<<"Details: "<<B1.getItem()<<" : "<<B1.getRate()<<" : "<<B1.getQuantity()<<endl<<endl;
                out.close();
                Sleep(3000);
                system("cls");
            }
        }
        else if(ch==2){
            system("cls");
            cout<<"Welcome to the Main Menu"<<endl;
            break;
        }
        else {
            cout<<"Invalid Input"<<endl;
        }
    }
}

void printBill() {
    system("cls");
    int total=0;
    while(true) {
        int ch;
        cout<<"1. Add Bill"<<endl;
        cout<<"2. Close Billing"<<endl<<endl;
        cout<<"Please enter you choice: ";
        cin>>ch;
        if(ch==1) {
            string item;
            int quan;
            cout<<"Enter the Item name: ";
            cin>>item;
            cout<<"Enter the quantity want: ";
            cin>>quan;
            ifstream in("D:/Bill.txt");
            ofstream out("D:/Bill Temp.txt");
            string line;
            bool to_get_data=false;
            while(getline(in,line)) {
                to_get_data=true;
                stringstream ss;
                ss<<line;
                string itemName;
                int itemRate,itemQuan;
                char neglector;
                ss>>itemName>>neglector>>itemRate>>neglector>>itemQuan;
                if(item==itemName) {
                    if(quan<=itemQuan) {
                        int amount=quan*itemRate;
                        cout<<"You bought "<<itemName<<" and it cost you: "<<amount<<endl;
                        itemQuan-=quan;
                        total+=amount;
                    }
                    else {
                        cout<<"Desired Number of pieces are not available"<<endl;
                    }
                }
            }
            if(to_get_data==false) {
                cout<<"Not item found"<<endl;
            }
            out.close();
            in.close();
            remove("D:/Bill.txt");
            rename("D:/Bill Temp.txt","D:/Bill.txt");
        }
        else {
            system("cls");
            break;
        }
    }
    system("cls");
    cout<<"Total Bill: "<<total<<endl;
    cout<<"Thank you visiting"<<endl<<endl;
    Sleep(5000);
}

int main() {
    Billing B1;
    while(true) {
        system("cls");
        int ch;
        cout<<"Welcome to NNNS Billing"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1. Add Item"<<endl;
        cout<<"2. Print Bill"<<endl;
        cout<<"3. Exit"<<endl<<endl;
        cout<<"Please enter you choice: ";
        cin>>ch;
        if(ch==1) {
            AddItem(B1);
            Sleep(1000);
        }
        else if(ch==2) {
            printBill();
        }
        else {
            system("cls");
            cout<<"Good Luck"<<endl;
            break;
        }
    }
    return 0;
}