#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct file 
{
	char filename[100];
	struct file *link;
};

struct directory
{
	char dirname[100];
	struct directory *nextdir;
	struct directory *subdir;
	struct file *files;
};


struct directory *search_dir(struct directory *p, char a[])
{
	struct directory *temp;
	temp = (p)->subdir;
	if (temp == NULL)
	{
		printf("Empty Directory\n");
		return NULL;
	}
	while (temp != NULL)
	{
		if (strcmp(temp->dirname, a) == 0)
		{
			printf("Directory found\n");
			return temp;
		}
		temp = temp->nextdir;
	}
	printf("No directory found named %s\n", a);
	return NULL;
}

void create_dir(struct directory *p)
{
	struct directory *temp, *newdir;
	temp = (p)->subdir;
	newdir = (struct directory *)malloc(sizeof(struct directory));
	char dirname[100];
	printf("Please enter the name of the new directory\n");
	scanf("%s", dirname);
	strcpy(newdir->dirname, dirname);
	newdir->nextdir = NULL;
	newdir->subdir = NULL;
	newdir->files = NULL;
	if (temp == NULL)
	{
		(p)->subdir = newdir;
		printf("New Directory created\n");
		return;
	}
	while (temp->nextdir != NULL)
	{
		temp = temp->nextdir;
	}
	temp->nextdir = newdir;
	printf("New directory created\n");
	return;
}

void delete_dir(struct directory *p, char a[])
{
	struct directory *temp, *z;
	temp = (p)->subdir;
	z = temp; 
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	if (strcmp(temp->dirname, a) == 0)
	{
		(p)->subdir = temp->nextdir;
		free(temp);
		printf("Directory deleted\n");
		return;
	}
	temp = temp->nextdir;
	while (temp != NULL)
	{
		if (strcmp(temp->dirname, a) == 0)
		{
			z->nextdir = temp->nextdir;
			free(temp);
			printf("Directory deleted\n");
			return;
		}
		z = temp;
		temp = temp->nextdir;
	}
	printf("No directory named %s found\n", a);
	return;
}

void display_subdir(struct directory *p)
{
	struct directory *temp;
	temp = (p)->subdir;
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	printf("The sub-directories are -->\n");
	while (temp != NULL)
	{
		printf("%s\n", temp->dirname);
		temp = temp->nextdir;
	}
	return;
}

void create_file(struct directory *p)
{
	struct file *temp, *newfile;
	temp = (p)->files;
	newfile = (struct file *)malloc(sizeof(struct file));
	char fname[100];
	printf("Please enter the name of the new file to be created\n");
	scanf("%s", fname);
	strcpy(newfile->filename, fname);
	newfile->link = NULL;
	if (temp == NULL)
	{
		(p)->files = newfile;
		printf("File created\n");
		return;
	}	
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = newfile;
	printf("File created\n");
	return;
}

void delete_file(struct directory *p, char a[])
{
	struct file *temp, *z;
	temp = (p)->files;
	z = temp;
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	if (strcmp(temp->filename, a) == 0)
	{
		(p)->files = temp->link;
		free(temp);
		printf("File deleted\n");
		return;
	}
	temp = temp->link;
	while (temp != NULL)
	{
		if (strcmp(temp->filename, a) == 0)
		{
			z->link = temp->link;
			free(temp);
			printf("File deleted\n");
			return;
		}
		z = temp;
		temp = temp->link;
	}
	printf("No file named %s found\n", a);
	return;
}

void display_files(struct directory *p)
{
	struct file *temp;
	temp = (p)->files;
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	printf("The file contents of the directory are -->\n");
	while (temp != NULL)
	{
		printf("%s\n", temp->filename);
		temp = temp->link;
	}
	return;
}

void search_file(struct directory *p, char a[])
{
	struct file *temp;
	temp = (p)->files;
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	while (temp != NULL)
	{
		if (strcmp(temp->filename, a) == 0)
		{
			printf("File %s found in directory %s\n", a, (p)->dirname);
			return;
		}
		temp = temp->link;
	}
	printf("No file named %s found\n", a);
	return;
}






int main ()
{
	struct directory *p, *temp1, *temp2;
	p = (struct directory *)malloc(sizeof(struct directory));
	printf ("Please enter the name of the main directory\n");
	char maindir[100], subdir[100], fname[100], rootdir[100];
	int choice;
	scanf("%s", rootdir);
	strcpy(p->dirname, rootdir);
	p->nextdir = NULL;
	p->subdir = NULL;
	p->files = NULL;
	while (1)
	{
		printf("\n*********************************************------\n");
		printf("Enter 1 to create a level 1 directory\n");
		printf("Enter 2 to create a level 2 directory\n");
		printf("Enter 3 to display all level 1 directories\n");
		printf("Enter 4 to display a set of level 2 directories\n");
		printf("Enter 5 to delete a level 1 directory\n");
		printf("Enter 6 to delete a level 2 directory\n");
		printf("Enter 7 to search for a level 1 directory\n");
		printf("Enter 8 to search for a level 2 directory\n");
		printf("Enter 9 to create a file\n");
		printf("Enter 10 to display all the files in a level 2 directory\n");
		printf("Enter 11 to search for a file\n");
		printf("Enter 12 to delete a file\n");
		printf("Enter 13 to exit\n");
		printf("Make your choice\n");
		scanf("%d", &choice);
		printf("*********************************************------\n\n");
		switch(choice)
		{
			case 1:printf("Creating a level 1 directory\n");
				create_dir(p);
				break;
			case 2:
				printf("Enter the name of the level 1 directory\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Creating a level 2 directory\n");
				create_dir(temp1);
				break;
			case 3:
				printf("Displaying level 1 directories\n");
				display_subdir(p);
				break;
			case 4:
				printf("Enter the name of the level 1 directory\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Displaying all level 2 directories\n");
				display_subdir(temp1);
				break;
			case 5:
				printf("Enter the name of the level 1 directory to be deleted\n");
				scanf("%s", maindir);
				delete_dir(p, maindir);
				break;
			case 6:
				printf("Enter the name of the level 1 directory\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Enter the name of the level 2 directory to be deleted\n");
				scanf("%s", subdir);
				delete_dir(temp1, subdir);
				break;
			case 7:
				printf("Enter the name of the level 1 directory to be searched for\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				break;
			case 8:
				printf("Enter the name of the level 1 directory\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Enter the name of the level 2 directory to be searched for\n");
				scanf("%s", subdir);
				temp2 = search_dir(temp1, subdir);
				break;
			case 9:
				printf("Level 1 directory : ?\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Level 2 directory : ?\n");
				scanf("%s", subdir);
				temp2 = search_dir(temp1, subdir);
				if (temp2 == NULL)
				{
					break;
				}
				create_file(temp2);
				break;
			case 10:
				printf("Level 1 directory : ?\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Level 2 directory : ?\n");
				scanf("%s", subdir);
				temp2 = search_dir(temp1, subdir);
				if (temp2 == NULL)
				{
					break;
				}
				display_files(temp2);
				break;
			case 11:
				printf("Level 1 directory : ?\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Level 2 directory : ?\n");
				scanf("%s", subdir);
				temp2 = search_dir(temp1, subdir);
				if (temp2 == NULL)
				{
					break;
				}
				printf("Enter the name of the file to be searched for\n");
				scanf("%s", fname);
				search_file(temp2, fname);
				break;
			case 12:
				printf("Level 1 directory : ?\n");
				scanf("%s", maindir);
				temp1 = search_dir(p, maindir);
				if (temp1 == NULL)
				{
					break;
				}
				printf("Level 2 directory : ?\n");
				scanf("%s", subdir);
				temp2 = search_dir(temp1, subdir);
				if (temp2 == NULL)
				{
					break;
				}
				printf("Enter the name of the file to be deleted\n");
				scanf("%s", fname);
				delete_file(temp2, fname);
				break;
			case 13:
				exit(0);
			default:
				printf("Please enter a valid choice\n");
		}
	}
}
