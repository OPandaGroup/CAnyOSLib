#include <stdio.h>

struct student {
	char *name;
	int age;

	void (*printInfo)(struct student *stu);
};

void printInfo(struct student *stu)
{
	printf("name = %s, age = %d", stu->name, stu->age);
}

int main(int argc, char**argv)
{
	struct student students[] = {
		{"zhangsan", 10, printInfo},
		{"lisi", 26, printInfo},
	};

	students[0].printInfo(&students[0]);
	students[1].printInfo(&students[1]);
}

