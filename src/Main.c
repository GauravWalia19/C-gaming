#include "functions.c"
#include "highscores.c"
int main()
{	
	/*ADD ENVIRONMENT VARIABLES FROM .bid FILE TO PROGRAM*/
	FILE *ptr;
	ptr = fopen(".bid","r");						//opening the .bid file
	if(ptr==NULL)									//if file not found
	{
		ptr = fopen(".bid","w");					//creating and writing new .bid file
		fprintf(ptr,"%d %d %c\n",1,1,'w');			//reseting the data to defaults
		fclose(ptr);								//close the file
		fopen(".bid","r");							//reopening the file for reading
	}

	fscanf(ptr,"%d %d %c\n",&BIDCARDID,&USERID,&OS);//reading and parsing the file
	printf("%d %d %c\n",BIDCARDID,USERID,OS);		//just for check
	
	/*LIMITING THE USERS OF APPLICATION*/
	if(USERID==USERS)								//limiting the database
	{
		colorSetting(RED);
		printf("USER LIMIT EXCEEDED\n");
		colorSetting(RESET);
		exit(1);
	}
	fclose(ptr);

	/*SKILLS INFO*/
	SKILLS = (char**)malloc(sizeof(char*)*10);
	/**
	 * SKILLS
	 * C
	 * C++
	 * JAVA
	 * PYTHON
	 * PERL
	 * RUBY
	 * HTML
	 * CSS
	 * JAVASCRIPT
	 * OTHER
	 **/
	//C
	SKILLS[0] = (char*)malloc(sizeof(char)*1);
	strcpy(SKILLS[0],"C");
	//C++
	SKILLS[1] = (char*)malloc(sizeof(char)*3);
	strcpy(SKILLS[1],"C++");
	//JAVA
	SKILLS[2] = (char*)malloc(sizeof(char)*4);
	strcpy(SKILLS[2],"JAVA");
	//PYTHON
	SKILLS[3] = (char*)malloc(sizeof(char)*6);
	strcpy(SKILLS[3],"PYTHON");
	//PERL
	SKILLS[4] = (char*)malloc(sizeof(char)*4);
	strcpy(SKILLS[4],"PERL");
	//RUBY
	SKILLS[5] = (char*)malloc(sizeof(char)*4);
	strcpy(SKILLS[5],"RUBY");
	//HTML
	SKILLS[6] = (char*)malloc(sizeof(char)*4);
	strcpy(SKILLS[6],"HTML");
	//CSS
	SKILLS[7] = (char*)malloc(sizeof(char)*3);
	strcpy(SKILLS[7],"CSS");
	//JAVASCRIPT
	SKILLS[8] = (char*)malloc(sizeof(char)*10);
	strcpy(SKILLS[8],"JAVASCRIPT");
	//OTHER
	SKILLS[9] = (char*)malloc(sizeof(char)*5);
	strcpy(SKILLS[9],"OTHER");

	/*COMPANY INFO*/
	COMPANIES = (char**)malloc(sizeof(char*)*10);
	/**
	 * COMPANIES
	 * GOOGLE
	 * AMAZON
	 * HP
	 * DELL
	 * VIRTUSA
	 * FACEBOOK
	 * INFOSYS
	 * APPLE
	 * XIOMI
	 * OTHER
	 **/
	COMPANIES[0] = (char*)malloc(sizeof(char)*6);
	strcpy(COMPANIES[0],"GOOGLE");
	COMPANIES[1] = (char*)malloc(sizeof(char)*6);
	strcpy(COMPANIES[1],"AMAZON");
	COMPANIES[2] = (char*)malloc(sizeof(char)*2);
	strcpy(COMPANIES[2],"HP");
	COMPANIES[3] = (char*)malloc(sizeof(char)*4);
	strcpy(COMPANIES[3],"DELL");
	COMPANIES[4] = (char*)malloc(sizeof(char)*7);
	strcpy(COMPANIES[4],"VIRTUSA");
	COMPANIES[5] = (char*)malloc(sizeof(char)*8);
	strcpy(COMPANIES[5],"FACEBOOK");
	COMPANIES[6] = (char*)malloc(sizeof(char)*7);
	strcpy(COMPANIES[6],"INFOSYS");
	COMPANIES[7] = (char*)malloc(sizeof(char)*5);
	strcpy(COMPANIES[7],"APPLE");
	COMPANIES[8] = (char*)malloc(sizeof(char)*5);
	strcpy(COMPANIES[8],"XIOMI");
	COMPANIES[9] = (char*)malloc(sizeof(char)*5);
	strcpy(COMPANIES[9],"OTHER");

	/*DESIGNATIONS info*/
	DESIGNATIONS = (char**)malloc(sizeof(char*)*10);
	/**
	 * DESIGNATIONS
	 * MANAGER
	 * CEO
	 * SOFTWARE DEVELOPER
	 * CLERK
	 * WEB DEVELOPER
	 * HACKER
	 * HR
	 * WEB DESIGNER
	 * ARTIST
	 * OTHER
	 **/
	//MANAGER
	DESIGNATIONS[0] = (char*)malloc(sizeof(char)*7);
	strcpy(DESIGNATIONS[0],"MANAGER");
	//CEO
	DESIGNATIONS[1] = (char*)malloc(sizeof(char)*3);
	strcpy(DESIGNATIONS[1],"CEO");
	//SOFTWARE DEVELOPER
	DESIGNATIONS[2] = (char*)malloc(sizeof(char)*18);
	strcpy(DESIGNATIONS[2],"SOFTWARE DEVELOPER");
	//CLERK
	DESIGNATIONS[3] = (char*)malloc(sizeof(char)*5);
	strcpy(DESIGNATIONS[3],"CLERK");
	//WEB DEVELOPER
	DESIGNATIONS[4] = (char*)malloc(sizeof(char)*13);
	strcpy(DESIGNATIONS[4],"WEB DEVELOPER");
	//HACKER
	DESIGNATIONS[5] = (char*)malloc(sizeof(char)*6);
	strcpy(DESIGNATIONS[5],"HACKER");
	//HR
	DESIGNATIONS[6] = (char*)malloc(sizeof(char)*2);
	strcpy(DESIGNATIONS[6],"HR");
	//WEB DESIGNER
	DESIGNATIONS[7] = (char*)malloc(sizeof(char)*12);
	strcpy(DESIGNATIONS[7],"WEB DESIGNER");
	//ARTIST
	DESIGNATIONS[8] = (char*)malloc(sizeof(char)*6);
	strcpy(DESIGNATIONS[8],"ARTIST");
	//OTHER
	DESIGNATIONS[9] = (char*)malloc(sizeof(char)*5);
	strcpy(DESIGNATIONS[9],"OTHER");

	// OS='l';
	/*OUR PROGRAM*/
	 //@tc => O(n^5)
	while(true)
	{
		welcome();					//welcome the user to the application 
		greetOptions();				//displat the main options of the application
	}

	/*freeing memory after the application crashes*/
	for(register int i=0;i<10;i++)
	{
		free(SKILLS[i]);
		free(COMPANIES[i]);
		free(DESIGNATIONS[i]);
	}
	free(SKILLS);
	free(COMPANIES);
	free(DESIGNATIONS);
	SKILLS=NULL;
	COMPANIES=NULL;
	DESIGNATIONS=NULL;
	
	// //flag for seraching name in database
	// bool flag = searchDB(find);
	
	return 0;
}
