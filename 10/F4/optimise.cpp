#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;


FILE *unoptimin, *optimout;


void fprint_optimise() {
	char *line1 = new char[512], *line2 = new char[512];
	line1[0] = line2[0] = '\0';
	bool cont_flag = false;
	size_t buf_len = 512;
	getline (&line2, &buf_len, unoptimin);
	cout << line1 << endl;
	// fprintf (optimout, line2);
	strcpy (line1, line2);

	while (getline (&line2, &buf_len, unoptimin) != -1) {
		if (cont_flag) {
			strcpy (line1, line2);
			cont_flag = false;
			continue;
		};

		if (strlen(line1) > 4 && strlen(line2) > 4
			&& line1[1]=='M' && line1[2]=='O' && line1[3]=='V' 
			&& line2[1]=='M' && line2[2]=='O' && line2[3]=='V') {
				char reg1, reg2, varname1[256], varname2[256];
				cout << "hello1!" << endl;
				sscanf (line1, "\tMOV %cX, %s\n", &reg1, varname1), sscanf (line2, "\tMOV %s %cX\n", varname2, &reg2); 
				int L = strlen(varname1);
				varname1[L] = ',', varname1[L+1] = '\0';
				cout << reg1 << " " << varname1 << " : " << varname2 << " " << reg2 << endl;
				if (reg1==reg2 && !strcmp(varname1, varname2)) {
					cont_flag = true;
				};
				sscanf (line2, "\tMOV %cX, %s\n", &reg1, varname1), sscanf (line1, "\tMOV %s %cX\n", varname2, &reg2); 
				L = strlen(varname1);
				varname1[L] = ',', varname1[L+1] = '\0';
				cout << reg1 << " " << varname1 << " : " << varname2 << " " << reg2 << endl;
				if (reg1==reg2 && !strcmp(varname1, varname2)) {
					cont_flag = true;
				};
		};



		if (strlen(line1) > 5 && strlen(line2) > 5 
			&& line1[1]=='P' && line1[2]=='U' && line1[3]=='S' && line1[4]=='H' 
			&& line2[1]=='P' && line2[2]=='O' && line2[3]=='P') {
				char reg1, reg2;
				cout << "hello2!" << endl;
				sscanf (line1, "\tPUSH %cX\n", &reg1), sscanf (line2, "\tPOP %cX\n", &reg2); 
				if (reg1 == reg2) {
					cont_flag = true;
					strcpy (line1, line2);
					continue;
				};
		};
		if (strlen(line1) > 4
			&& line1[1]=='A' && line1[2]=='D' && line1[3]=='D') {
				char reg1, add[256];
				cout << "hello3!" << endl;
				sscanf (line1, "\tADD %cX, %s\n", &reg1, add);
				if ((reg1=='A' || reg1=='B' || reg1=='C' || reg1=='D') && !strcmp(add, "0")) {
					cout << reg1 << " " << add << endl;
					strcpy (line1, line2);
					continue;
				};
		};

		if (strlen(line1) > 4
			&& line1[1]=='M' && line1[2]=='U' && line1[3]=='L') {
				char mul[256];
				cout << "hello4!" << endl;
				sscanf (line1, "\tMUL %s\n", mul);
				if (!strcmp(mul, "1")) {
					cout << mul << endl;
					strcpy (line1, line2);
					continue;
				};
		};
		//cout << line1 << line2 << endl;
		fprintf (optimout, line1);
		strcpy (line1, line2);
		
	};
	fprintf (optimout, line1);
};


int main() {
	unoptimin = fopen ("test1_i_code.asm", "r");
	optimout = fopen("test1_i_optcode.asm", "w");
	fprint_optimise();
	return 0;    
};