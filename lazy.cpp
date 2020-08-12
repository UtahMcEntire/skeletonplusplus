/*Author: Utah McEntire || utahmcentire@gmail.com || https://github.com/UtahMcEntire
 *Purpose: This program will set up the basic c++
 *		   program source code so you can get started
 *		   on the parts that matter.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

int main(){
		
	string yeet, classcode, sectionnum, name, labnum, duedate, progtitle, filename, mainDef, userFuncDec, userFuncDef, headerstr, impstr, addfiles, filecloser;
	string progdesc, functype, funcname, skipthis, parametertype, parametername, dataname, datavar, anotherfile, inorout, classname, returnornot, returnvalue, overwritechoice;
	string classchoice, ynchoice, incfstreamcassert, usenamespacestd, createfunc, hasparameters, passbyreference, viewfile, fileline;
	string gator="                  _.---._     .---.\n         __...---' .---. `---'-.   `.\n     .-''__.--' _.'( | )`.  `.  `._ :\n   .'__-'_ .--'' ._`---'_.-.  `.   `-`.\n          ~ -._ -._``---. -.    `-._   `.\n               ~ -.._ _ _ _ ..-_ `.  `-._``--.._\n                            -~ -._  `-.  -. `-._``--.._.--''. \n                                 ~ ~-.__     -._  `-.__   `. `. \n                                       ~~ ~---...__ _    ._ .` `. \n                                                   ~  ~--.....--~`\n";
	bool firstparameter;
	fstream myprog, myprogimp, myprogheader;
	int progdesclength, descnewline=61;
	
	cout<<"\n        __           __          __\n"
		<<"  _____|  | __ ____ |  |   _____/  |_  ____  ____      __        __\n"
		<<" /  ___/  |/ // __ \\|  | _/ __ \\   __\\/  _ \\|    \\  __|  |___ __|  |___\n"
		<<" \\___ \\|    <\\  ___/|  |_\\  ___/|  | (  <_> )  |  \\/__    __//__    __/\n"
		<<"/______>__|_ \\\\_____>____/\\_____>__|  \\____/|__|  /   |__|      |__|\n"
		<<"============\\/==================================\\/======================\n"
		<<"This program will output a .cpp file with all the bells and whistles that\n"
		<<"you've chosen. Options include the course/lab/date/name info section, #include\n"
		<<"options, any functions to create, input/output files, as well as class options\n"
		<<"including header.h and implementation.cpp files and a default const/destructor.\n\n";
	
	cout<<"Part 1:   _     ____   __    ___   ____  ___\n"
		<<"---------| |_| | |_   / /\\  | | \\ | |_  | |_)---------\n"
		<<"         |_| | |_|__ /_/--\\ |_|_/ |_|__ |_| \\\n\n";
	
	cout<<"Class code (ex: 2170, 3080, 3110): ";
	cin>>classcode;
	cout<<"Class section (ex: 001, 007): ";
	cin>>sectionnum;
	cout<<"Your name: ";
	cin.ignore(120, '\n');
	getline(cin, name);
	cout<<"OLA/CLA/LAB name (ex: lab1 or ola3): ";
	getline(cin, labnum);
	cout<<"Program due date (mm/dd/yyyy): ";
	getline(cin, duedate);
	cout<<"Program Title (ex. Coin Counter): ";
	getline(cin, progtitle);
	cout<<"Program filename (ex. coins.cpp): ";
	getline(cin, filename);
	cout<<"Program description: ";
	getline(cin, progdesc);
	
	progdesclength=progdesc.length();
	
	// Inserts newline characters to keep description at a reasonable wordwrap length
	while (progdesclength>descnewline){
		progdesc.insert(descnewline,"-\n// ");
		descnewline+=75;
	}
	
	// Adds the .cpp file extention if user doesnt
	if (filename.find(".cpp") == string::npos){
		filename=filename.append(+".cpp");
	}
	
	cout<<"If "<<filename<<" already exists, this will overwrite that file! Do you wish to continue? (y/n): ";
		cin>>overwritechoice;
		if (overwritechoice=="y" or overwritechoice=="Y"){
			// Creates main .cpp file for input, output, and clears data if file already exists
			myprog.open(filename, ios::in | ios::out | ios::trunc);
			assert(myprog);
		}
		else {
			cout<<"\nYou chose to abort so no files were created or overwritten. Here's a Later Gator:\n";
			cout<<gator;
			return 0;
		}

	if (myprog.is_open()){
		cout<<"\nThe file \""<<filename<<"\" has been successfully created!";
	}
	else {
		cout<<"Oh shit, there was some stupid issue creating "<<filename<<" :/\n";
		return 1;
	}
	
	myprog<<"// "<<labnum<<" BY "<<name<<", CSCI "<<classcode<<"-"<<sectionnum<<", Due: "<<duedate<<"\n";
	myprog<<"// PROGRAM ID: "<<filename<<" / "<<progtitle<<"\n";
	myprog<<"// AUTHOR: "<<name<<"\n";
	myprog<<"// INSTALLATION: MTSU\n";
	myprog<<"// REMARKS: "<<progdesc<<"\n// Started via Skeleton++\n\n";
	
	cout<<"\n\n"
		<<"Part 2:   __    _      __    __   __   ____  __\n"
		<<"---------/ /`  | |    / /\\  ( (` ( (` | |_  ( (`---------\n"
		<<"         \\_\\_, |_|__ /_/--\\ _)_) _)_) |_|__ _)_)\n\n";
	
	cout<<"Does this program require header and implementation files (ex: list.h & list.cpp)? (y/n): ";
	cin>>classchoice;
	if (classchoice=="y" or classchoice=="Y"){
		cout<<"What will be your class name? ";
		cin>>classname;
		
		cout<<"If the files "<<classname<<".cpp and "<<classname<<".h already exist, they will be overwritten! Do you wish to continue? (y/n): ";
		cin>>ynchoice;
		if (ynchoice=="y" or ynchoice=="Y"){
			myprogheader.open(classname+".h", ios::in | ios::out | ios::trunc);
			assert(myprogheader);

			myprogimp.open(classname+".cpp", ios::in | ios::out | ios::trunc);
			assert(myprogimp);

			if (myprogheader.is_open() and myprogimp.is_open()){
				cout<<"\n\n"<<classname<<".h and "<<classname<<".cpp have been successfully created!\n";
			}
			else {
				cout<<"Oh shit, there was some stupid issue creating the files :/\nWe out.";
				return 1;
			}
		}
		else if (ynchoice=="n" or ynchoice=="N"){
			cout<<"\nYou chose to abort so no files were created or overwritten. Here's a Later Gator:\n";
			cout<<gator;
			return 0;
		}
		else {
			cout<<"That was not a valid input stupid, try again. (y/n): ";
		}
		myprog<<"#include \""<<classname<<".h\"\n";		
		
		if (classchoice=="y" or classchoice=="Y"){
			myprogheader<<"// "<<labnum<<" BY "<<name<<", CSCI "<<classcode<<"-"<<sectionnum<<", Due: "<<duedate<<"\n";
			myprogimp<<"// "<<labnum<<" BY "<<name<<", CSCI "<<classcode<<"-"<<sectionnum<<", Due: "<<duedate<<"\n";
		}
		if (classchoice=="y" or classchoice=="Y"){
			myprogheader<<"// PROGRAM ID: "<<filename<<" / "<<progtitle<<"\n";
			myprogimp<<"// PROGRAM ID: "<<filename<<" / "<<progtitle<<"\n";
		}
		if (classchoice=="y" or classchoice=="Y"){
			myprogheader<<"// AUTHOR: "<<name<<"\n";
			myprogimp<<"// AUTHOR: "<<name<<"\n";
		}
		if (classchoice=="y" or classchoice=="Y"){
			myprogheader<<"// INSTALLATION: MTSU\n";
			myprogimp<<"// INSTALLATION: MTSU\n";
		}
		if (classchoice=="y" or classchoice=="Y"){
			myprogheader<<"// REMARKS: "<<progdesc<<"\n\n";
			myprogimp<<"// REMARKS: "<<progdesc<<"\n\n";
		}
		
		myprogheader<<"#ifndef "<<classname<<"_H\n#define "<<classname<<"_H\n\n";
		myprogimp<<"#include \""<<classname<<".h\"\n";
	}
	else if (classchoice=="n" or classchoice=="N"){
		cout<<"\nWell thank fuck.";
	}
	
	cout<<"\n\n";
	cout<<"Part 3:   _   _      __    _     _     ___   ____\n"
		<<"---------| | | |\\ | / /`  | |   | | | | | \\ | |_ ---------\n"
		<<"         |_| |_| \\| \\_\\_, |_|__ \\_\\_/ |_|_/ |_|__ \n\n";
		
	cout<<"For each #include option, enter y to include or n to skip that one.\n"
		<<"Or enter y now to automatically include all most commonly used #include options. (y/n): ";
	cin>>yeet;
	
	if (yeet=="y" or yeet=="Y"){
		myprog<<"#include <iostream>\n#include <fstream>\n#include <cassert>\n#include <string>\n#include <iomanip>\n#include <cstdlib>\nusing namespace std;\n\n";
		if (classchoice=="y" or classchoice=="Y"){
			myprogimp<<"#include <iostream>\n#include <fstream>\n#include <cassert>\n#include <string>\n#include <iomanip>\n#include <cstdlib>\n#include <cstddef> //For NULL\nusing namespace std;\n\n";
			myprogimp<<"//Default constructor\n"<<classname<<"::"<<classname<<"(){\n\t\n}\n\n";
			myprogheader<<"#include <iostream>\n#include <fstream>\n#include <cassert>\n#include <string>\n#include <iomanip>\n#include <cstdlib>\n#include <cstddef> //For NULL\nusing namespace std;\n\n";
		}
	}
	
	else {
		cout<<"#include <iostream>? - basic if/else logic (y/n): ";
		cin>>ynchoice;
		if (ynchoice=="y"){
			myprog<<"#include <iostream>\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"#include <iostream>\n";
				myprogheader<<"#include <iostream>\n";
			}
		}
		cout<<"#include <fstream> & <cassert>? - reading in/output file (y/n): ";
		cin>>incfstreamcassert;
		if (incfstreamcassert=="y"){
			myprog<<"#include <fstream>\n#include <cassert>\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"#include <fstream>\n#include <cassert>\n";
				myprogheader<<"#include <fstream>\n#include <cassert>\n";
			}
		}
		cout<<"#include <string>? - string manipulation (y/n): ";
		cin>>ynchoice;
		if (ynchoice=="y"){
			myprog<<"#include <string>\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"#include <string>\n";
				myprogheader<<"#include <string>\n";
			}
		}
		cout<<"#include <iomanip>? - word formatting(setw) (y/n): ";
		cin>>ynchoice;
		if (ynchoice=="y"){
			myprog<<"#include <iomanip>\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"#include <iomanip>\n";
				myprogheader<<"#include <iomanip>\n";
			}
		}
		cout<<"#include <cstdlib>? - big ol library (y/n): ";
		cin>>ynchoice;
		if (ynchoice=="y"){
			myprog<<"#include <cstdlib>\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"#include <cstdlib>\n";
				myprogheader<<"#include <cstdlib>\n";
			}
		}
		cout<<"using namespace std;? (y/n): ";
		cin>>usenamespacestd;
		if (classchoice=="y" or classchoice=="Y"){
			myprogimp<<"#include <cstddef> //For NULL\n";
		}
		if (usenamespacestd=="y"){
			myprog<<"\nusing namespace std;\n\n";
			if (classchoice=="y" or classchoice=="Y"){
				myprogimp<<"\nusing namespace std;\n\n";
				myprogheader<<"\nusing namespace std;\n\n";
			}
		}
		if (classchoice=="y" or classchoice=="Y"){
			myprogimp<<"//Default constructor\n"<<classname<<"::"<<classname<<"(){\n/t\n}\n\n";
		}
	}
	
	cout<<"\n\n"; // Creates empty functions with parameters and asks if passing by reference
	cout<<"Part 4:   ____  _     _      __   _____  _   ___   _      __\n"
		<<"---------| |_  | | | | |\\ | / /`   | |  | | / / \\ | |\\ | ( (`---------\n"
		<<"         |_|   \\_\\_/ |_| \\| \\_\\_,  |_|  |_| \\_\\_/ |_| \\| _)_)\n\n";
	
	cout<<"We will create empty functions for you here!\n**int main() is automatically included**\n\n"
		<<"Create a new custom function? (y/n): ";
	cin>>createfunc;
	while (createfunc=="y" or createfunc=="Y"){
		firstparameter=true;
		cout<<"Enter function type, name & wether or not it has parameters. (ex: void insert y): ";
		cin>>functype>>funcname>>hasparameters;
		
		if (hasparameters=="n" or hasparameters=="N"){
			userFuncDec.append("\n");
			if (classchoice=="y" or classchoice=="Y"){
				userFuncDec.append("\t");
			}
			userFuncDec.append(functype+" ");
			userFuncDec.append(funcname+"();\n");
			userFuncDef.append("\n"+functype+" ");
			if (classchoice=="y" or classchoice=="Y"){
				userFuncDef.append(classname+"::");
			}
			userFuncDef.append(funcname+"(){\n\t");
			if(functype!="void"){
				cout<<"Would you like to enter a value for "<<functype<<" "<<funcname<<" to return? (y/n): ";
				cin>>returnornot;
				if (returnornot=="y" or returnornot=="Y"){
					cout<<"Enter the value to return (ex. average):";
					cin>>returnvalue;
					userFuncDef.append("\n\treturn "+returnvalue+";\n}\n\n");
				}
			}
		}
		while (hasparameters=="y" or hasparameters=="Y"){
			cout<<"Enter the new parameter type: ";
			cin>>parametertype;
			cout<<"Enter the new parameter name: ";
			cin>>parametername;
			if (firstparameter==true){
				do {
					cout<<"Pass \""<<parametertype<<" "<<parametername<<"\" by &reference? (y/n): ";
					cin>>passbyreference;
					if (passbyreference=="n" or passbyreference=="N"){
						userFuncDec.append("\n");
						if (classchoice=="y" or classchoice=="Y"){
							userFuncDec.append("\t");
						}
						userFuncDec.append(functype+" ");
						userFuncDec.append(funcname+"("+parametertype+" "+parametername);
						userFuncDef.append("\n"+functype+" ");
						if (classchoice=="y" or classchoice=="Y"){
							userFuncDef.append(classname+"::");
						}
						userFuncDef.append(funcname+"("+parametertype+" "+parametername);
					}
					else if (passbyreference=="y" or passbyreference=="Y"){
						userFuncDec.append("\n");
						if (classchoice=="y" or classchoice=="Y"){
							userFuncDec.append("\t");
						}
						userFuncDec.append(functype+" ");
						userFuncDec.append(funcname+"("+parametertype+" &"+parametername);
						userFuncDef.append(functype+" ");
						if (classchoice=="y" or classchoice=="Y"){
							userFuncDef.append(classname+"::");
						}
						userFuncDef.append(funcname+"("+parametertype+" &"+parametername);
					}
					else {
						cout<<"Invalid input.\n";
					}
				} while (passbyreference!="y" and passbyreference!="n" and passbyreference!="Y" and passbyreference!="N");
			}
			else{
				do {
					cout<<"Pass \""<<parametertype<<" "<<parametername<<"\" by &reference? (y/n): ";
					cin>>passbyreference;
					if (passbyreference=="n" or passbyreference=="N"){
						userFuncDec.append(", "+parametertype+" "+parametername);
						userFuncDef.append(", "+parametertype+" "+parametername);
					}
					else if (passbyreference=="y" or passbyreference=="Y"){
						userFuncDec.append(", "+parametertype+" &"+parametername);
						userFuncDef.append(", "+parametertype+" &"+parametername);
					}
					else {
						cout<<"Invalid input.\n";
					}
				} while (passbyreference!="y" and passbyreference!="n" and passbyreference!="Y" and passbyreference!="N");
			}
			firstparameter=false;
			cout<<"Enter another parameter? (y/n): ";
			cin>>hasparameters;
			cout<<"\n";
			
			if (hasparameters=="n" or hasparameters=="N"){
				userFuncDec.append(");\n");
				userFuncDef.append("){\n\t");
				if(functype!="void"){
					cout<<"Would you like to enter a value for "<<functype<<" "<<funcname<<" to return? (y/n): ";
					cin>>returnornot;
					if (returnornot=="y" or returnornot=="Y"){
						cout<<"Enter the value to return (ex. average):";
						cin>>returnvalue;
						userFuncDef.append("\n\treturn "+returnvalue+";");
					}
				}
				userFuncDef.append("\n}\n\n");
			}
		}
		cout<<"\nCreate another custom function? (y/n): ";
		cin>>createfunc;
	}
	mainDef.append("\nint main(){\n");

	// If opted in for <fstream> gives option to add input/output files
	if (incfstreamcassert=="y" or incfstreamcassert=="Y" or yeet=="y" or yeet=="Y"){
		cout<<"\n\nPart 5:   _   _       __  ___   _    _____      ____  _   _     ____  __\n"
			<<"---------| | | |\\ |  / / / / \\ | | |  | |      | |_  | | | |   | |_  ( (`---------\n"
			<<"         |_| |_| \\| /_/  \\_\\_/ \\_\\_/  |_|      |_|   |_| |_|__ |_|__ _)_) \n\n";
		cout<<"You #included <fstream>, would you like to add an input/output file? (y/n): ";
		cin>>addfiles;
		if (addfiles=="y" or addfiles=="Y"){
			do {
				mainDef.append("\t//opens necessary files\n");
				cout<<"Input or output file? (in/out): ";
				cin>>inorout;
				cout<<"Enter variable name for a file (ex: myIn): ";
				cin>>datavar;
				if (inorout=="in" or inorout=="IN" or inorout=="In" or inorout =="iN"){
					mainDef.append("\tifstream "+datavar+";\n");
				}
				else if (inorout=="out" or inorout=="OUT" or inorout=="Out"){
					mainDef.append("\tofstream "+datavar+";\n");
				}
				filecloser=("\n\t"+datavar+".close();\n");
				cout<<"Enter the actual filename with .extension (ex: inventory.dat): ";
				cin>>dataname;
				mainDef.append("\t"+datavar+".open(\""+dataname+"\");\n"+"\tassert("+datavar+");\n\n");
				cout<<"\nDeclare another input/output file? (y/n): ";
				cin>>anotherfile;
			} while (anotherfile=="y" or anotherfile=="Y");
			
			if (incfstreamcassert=="y" or yeet=="y"){
				mainDef.append("\n\t//close the opened files"+filecloser);
			
			}
		}
	}
	
	mainDef.append("\n\treturn 0;\n}\n\n");
	
	if (classchoice=="n" or classchoice=="N"){
		myprog<<userFuncDec;
		myprog<<mainDef;
		myprog<<userFuncDef;
	}
	else if (classchoice=="y" or classchoice=="Y"){
		myprog<<mainDef;
		myprogheader<<"\n\nclass "<<classname<<"{\nPublic:\n\n\t//Constructor\n\t"<<classname<<"();\n";
		myprogheader<<userFuncDec;
		myprogheader<<"\n\t//Destructor\n\t~"<<classname<<"();\n\nPrivate:\n\t\n};\n\n#endif";
		myprogimp<<userFuncDef;
		myprogimp<<"\n//Destructor\n"<<classname<<"::~"<<classname<<"(){\n\t\n}";
	}
	
	
	// Will allow preview of all created files in terminal
	cout<<"\n\nYour program template has been created wherever this starter program file is located :)\n"
		<<"Would you like to preview "<<filename;
		if (classchoice=="y" or classchoice=="Y"){
			cout<<", "<<classname<<".h, and "<<classname<<".cpp";
		}
	cout<<" now? (y/n): ";
	cin>>viewfile;
	cout<<"\n\n";
	
	if (viewfile=="y" or viewfile=="Y"){
		for (int i = 0; i < 10; i++){	//------main prog filename------
				cout<<"-";
			}
		cout<<" ["<<filename<<"] ";
		for (int i = 0; i < 10; i++){
			cout<<"-";
		}
		
		if (myprog.is_open()){				// main file body
			cout<<"\n";
			myprog.clear();
			myprog.seekg(0, ios::beg);
			while (getline(myprog, fileline)) {
				cout<<fileline<<endl;
			}
			cout<<"\n";
		}
		
		if (myprogimp.is_open()){
			for (int i = 0; i < 10; i++){	//------implementation filename------
				cout<<"-";
			}
			cout<<" ["<<classname<<".cpp] ";
			for (int i = 0; i < 10; i++){
				cout<<"-";
			}
			cout<<"\n";
			myprogimp.clear();
			myprogimp.seekg(0, ios::beg);
			while (getline(myprogimp, fileline)) { //implementation file body
				cout<<fileline<<endl;
			}
			cout<<"\n";
		}
		
		if (myprogheader.is_open()){
			for (int i = 0; i < 10; i++){	//------header filename------
				cout<<"-";
			}
			cout<<" ["<<classname<<".h] ";
			for (int i = 0; i < 10; i++){
				cout<<"-";
			}
			cout<<"\n";
			myprogheader.clear();
			myprogheader.seekg(0, ios::beg);
			while (getline(myprogheader, fileline)) { //header file body
				cout<<fileline<<endl;
			}
			cout<<"\n";
		}
		
		for (int i = 0; i < 30; i++){		//------------
			cout<<"-";
		}
		cout<<"\n\n";
	}
	if (myprog.is_open()){
		myprog.close();
	}
	if (myprogheader.is_open()){
		myprogheader.close();
	}
	if (myprogimp.is_open()){
		myprogimp.close();
	}
	return 0;
}
 
