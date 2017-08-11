#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct file
{
	char filename[100];
	struct directory *parent;
	struct file *link;
};

struct directory 
{
	char dirname[100];
	struct directory *nextdir;
	struct directory *subdir;
	struct directory *parentdir;
	struct file *files;
};






int main ()
{
	char maindirname[100];
	printf("  the name of the root directory\n");
	scanf("%s", maindirname);
	struct directory *p, *temp, *newdir;
	p = (struct directory *)malloc(sizeof(struct directory *));
	strcpy(p->dirname, maindirname);
	p->parentdir = NULL;
	p->subdir = NULL;
	p->nextdir = NULL;
	p->files = NULL;
	temp = p;
	char dirname[100], filename[100];
	printf("Present working directory presently set to the root directory\n");
	int choice;
	while (1)
	{
		printf("\n******************************************************\n");
		printf("  1 : display the current directory\n");
		printf("  2 : change  into sub-directory\n");
		printf("  3 : go the parent directory of the present directory\n");
		printf("  4 : display all the files in the present directory\n");
		printf("  5 : display all the subdirectories of the present directory\n");
		printf("  6 : search for a directory\n");
		printf("  7 : search for a file in the present directory\n");
		printf("  8 : insert a file into the present directory\n");
		printf("  9 : insert a sub-directory into the directory\n");
		printf("  10 : delete a sub-directory\n");
		printf("  11 : delete a file\n");
		printf("  12 : exit\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		printf("******************************************************\n\n");
		switch(choice)
		{
			case 1:
				pwd(temp);
				break;
			case 2:
				printf("  the name of the directory\n");
				scanf("%s", dirname);
				newdir = search_dir(temp, dirname);
				if (newdir == NULL)
				{
					printf("No directory found\n");
					break;
				}
				temp = newdir;
				printf("Directory changed\n");
				break;
			case 3:
				if (temp->parentdir == NULL)
				{
					printf("The current directory is the present directory\n");
					break;
				}
				temp = temp->parentdir;
				break;
			case 4:
				 disfile(temp);
				break;
			case 5:
				display_dir(temp);
				break;
			case 6:
				printf("  the name of the directory to be searched for in the present directory\n");
				scanf("%s", dirname);
				newdir = search_dir(temp, dirname);
				break;
			case 7:
				printf("  the name of the file to be searched for in the present directory\n");
				scanf("%s", filename);
				search_file(temp, filename);
				break;
			case 8:
				insert_file(temp);
				break;
			case 9:
				insert_dir(temp);
				break;
			case 10:
				printf("  the name of the directory to be deleted\n");
				scanf("%s", dirname);
				delete_dir(temp, dirname);
				break;
			case 11:
				printf("  the name of the file to be deleted\n");
				scanf("%s", filename);
				delete_file(temp, filename);
				break;
			case 12:
				return 0;
			default:
				printf("  invalid choice\n");
		}
	}
	return 0;
}