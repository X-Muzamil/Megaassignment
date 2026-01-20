#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

struct student {
    string id, name;
    int age;
    float English, PF, Discrete, PS, Islamiat, sum, percentage;
    char grade;
};

int size=0;  
void calculate(student &s) {
    s.sum = s.English + s.PF + s.Discrete + s.PS + s.Islamiat;
    s.percentage = (s.sum / 500.0) * 100; 

    if(s.percentage >= 80) s.grade = 'A';
    else if(s.percentage >= 70) s.grade = 'B';
    else if(s.percentage >= 60) s.grade = 'C';
    else if(s.percentage >= 40) s.grade = 'D';
    else s.grade = 'F';
}

// Data entry
void dataentry(student s[]) {
    cout << "Enter how many students do you want to enter: ";
    cin >> size;

    for(int i = 0; i < size; i++) {
        cout << "Enter student " << i+1 << " id: ";
        cin >> s[i].id;

        cin.ignore();
        cout << "Enter student " << i+1 << " name: ";
        getline(cin, s[i].name);

        cout << "Enter student " << i+1 << " age: ";
        cin >> s[i].age;

        cout << "Enter the marks of English: ";
        cin >> s[i].English;

        cout << "Enter the marks of Discrete: ";
        cin >> s[i].Discrete;

        cout << "Enter the marks of PF: ";
        cin >> s[i].PF;

        cout << "Enter the marks of PS: ";
        cin >> s[i].PS;

        cout << "Enter the marks of Islamiat: ";
        cin >> s[i].Islamiat;

        calculate(s[i]);
        cout << endl;
    }
}

// Save to file
void savefile(student s[]) {
	
	
    ofstream file("student.txt", ios::app); 
    if(!file) {
        cout << "File not found!";
        return;
    }
	
    for(int i = 0; i < size; i++) {
file << left << setw(15) << s[i].id << setw(20) << s[i].name  << setw(15) << s[i].age << setw(15) << s[i].sum << setw(15) << fixed << setprecision(2) << s[i].percentage << setw(15) << s[i].grade << endl;
    }

    file.close();
    
}

// Read data
void readdata() {

    ifstream file("student.txt");
    if(!file) {
        cout << "File not found!";
        return;
    }

    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Search by student ID
void searchdata(student s[]) {
    string searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    bool found = false;
    for(int i = 0; i < size; i++) {
        if(s[i].id == searchId) {
            cout << "Student found: " << s[i].name << "   " << s[i].percentage << "%, Grade " << s[i].grade << "\n";
            found = true;
            break;
        }
    }
    if(!found) cout << "Student not found!\n";
}

// Delete by student ID
void deletedata(student s[]) {
    string deleteId;
    cout << "Enter student ID to delete: ";
    cin >> deleteId;

    bool found = false;
    for(int i = 0; i < size; i++) {
        if(s[i].id == deleteId) {
            for(int j = i; j < size-1; j++) {
                s[j] = s[j+1];
            }
            size--;
            
            found = true;
            break;
        }
    }
    if(!found) cout << "Student not found!\n";
}

// Edit by student ID
void editdata(student s[]) {
    string editId;
    cout << "Enter student ID to edit: ";
    cin >> editId;

    bool found = false;
    for(int i = 0; i < size; i++) {
        if(s[i].id == editId) {
            cout << "Editing student " << s[i].name << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s[i].name);
            cout << "Enter new age: ";
            cin >> s[i].age;
            cout << "Enter new marks (English, Discrete, PF, PS, Islamiat): ";
            cin >> s[i].English >> s[i].Discrete >> s[i].PF >> s[i].PS >> s[i].Islamiat;
            calculate(s[i]);
            
           found = true;
            break;
        }
    }
   if(!found) cout << "Student not found!\n";
}

// Sorting of students 
void Sorting(student s[],int size) {
    int choice;
    cout << "Enter 1 to sort by Name (A - Z)" << endl;
    cout << "Enter 2 to sort by Percentage (High --> Low)" << endl;
    cout << "Enter 3 to sort by Age (Low --> High)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    student temp;

    switch(choice) {
        case 1: 
            for(int i = 0; i < size - 1; i++) {
                for(int j = i + 1; j < size; j++) {
                    if(s[i].name > s[j].name) {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
            cout << "Sorted by Name (A-Z)" << endl;
             for(int i = 0; i < size; i++) {
      		for(int i = 0; i < size; i++) {
        cout << left << setw(15) << s[i].id << setw(20) << s[i].name << setw(15) << s[i].age << setw(15) << s[i].sum << setw(15) << fixed << setprecision(2) << s[i].percentage << setw(15) << s[i].grade << endl;
    }
	  		 break;
		
		
    }
			
        case 2: 
            for(int i = 0; i < size - 1; i++) {
                for(int j = i + 1; j < size; j++) {
                    if(s[i].percentage < s[j].percentage) {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
            cout << "Sorted by Percentage (High-Low)" << endl;
  			for(int i = 0; i < size; i++) {
        cout << left << setw(15) << s[i].id << setw(20) << s[i].name << setw(15) << s[i].age << setw(15) << s[i].sum << setw(15) << fixed << setprecision(2) << s[i].percentage << setw(15) << s[i].grade << endl;
    }
  			 break;

        case 3: 
            for(int i = 0; i < size - 1; i++) {
                for(int j = i + 1; j < size; j++) {
                    if(s[i].age > s[j].age) {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
            cout << "Sorted by Age (Low-High)" << endl;
    	for(int i = 0; i < size; i++) {
        cout << left << setw(15) << s[i].id << setw(20) << s[i].name << setw(15) << s[i].age << setw(15) << s[i].sum << setw(15) << fixed << setprecision(2) << s[i].percentage << setw(15) << s[i].grade << endl;
    }
		 break;

        default:
            cout << "Invalid choice!" << endl;
    }

   
    
}




int main() {
    int choice;
    student s[100];
    

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Data Entry\n";
        cout << "2. Save Data to File\n";
        cout << "3. Read Data from File\n";
        cout << "4. Search Data\n";
        cout << "5. Delete Data\n";
        cout << "6. Edit Data\n";
        cout << "7. Sort Data Alphabetically\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
			dataentry(s); 
			break;
            case 2: 
		 savefile(s); 
		 break;
		 
            case 3: 
            cout << left << setw(15) << "ID" << setw(20) << "Name" << setw(15) << "Age" << setw(15) << "Total Marks" << setw(15) << "Percentage" <<setw(15) << "Grade" << endl;
         cout << string(95, '-') << endl;
			readdata(); 
			break;
            case 4: 
			searchdata(s);
			 break;
            case 5: 
			deletedata(s); 
			break;
            case 6: 
			editdata(s); 
			break;
			
            case 7: 
			Sorting(s,size);
			 break;
            
            default: cout << "Invalid choice!\n";
        }
    } while(choice !=0);

   
}