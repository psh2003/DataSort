#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMPLOYEE 10

typedef struct {
	char name[10], dept[30], phone[25];
	int num, birth;
}Employee;
int compare(const void* a, const void* b)
{
	Employee* pa = (Employee*)a;
	Employee* pb = (Employee*)b;

	return strcmp(pa->name, pb->name);
}
int compareNum(const void* a, const void* b)  //�������� ����
{
	Employee* pa = (Employee*)a;
	Employee* pb = (Employee*)b;

	if (pa->num > pb->num)
		return 1;
	else if (pa->num < pb->num)
		return -1;
	else
		return 0;
}
int compareBirth(const void* a, const void* b)
{
	Employee* pa = (Employee*)a;
	Employee* pb = (Employee*)b;

	if (pa->birth > pb->birth)
		return 1;
	else if (pa->birth < pb->birth)
		return -1;
	else
		return 0;
}
int compareDept(const void* a, const void* b)
{
	Employee* pa = (Employee*)a;
	Employee* pb = (Employee*)b;

	return strcmp(pa->dept, pb->dept);
}
int comparePhone(const void* a, const void* b)
{
	Employee* pa = (Employee*)a;
	Employee* pb = (Employee*)b;

	return strcmp(pa->phone, pb->phone);
}
int main() {
	FILE *fp, *fp2;
	int i, j,n;
	const int max = 100;
	char line[100];
	Employee temp;
	Employee employee[MAX_EMPLOYEE];
	n = sizeof(employee) / sizeof(Employee);
	fp = fopen("PersonInfo.txt", "rt");

	if (fp == NULL)

	{
		printf("\n ���� �б� ����\n");
		exit(1);
	}
	for (i = 0; i < 10; i++) {
		fgets(line, max, fp);
		sscanf(line, "%[^,], %d, %d, %[^,], %s", employee[i].name, &employee[i].num, &employee[i].birth, employee[i].dept, &employee[i].phone);
	}
	fclose(fp);
	int choose;
	printf("������ ������ ��ȣ�� �Է��ϼ���.\n");
	printf("1. �̸� 2. ��� 3. ������� 4. �μ��� 5. ��ȭ��ȣ\n");
	scanf("%d", &choose);
	switch (choose) {
	case 1:
		qsort(employee,10,sizeof(Employee),compare);  break;

	case 2:
		qsort(employee, 10, sizeof(Employee), compareNum);  break;

	case 3:
		qsort(employee, 10, sizeof(Employee), compareBirth);  break;

	case 4:
		qsort(employee, 10, sizeof(Employee), compareDept);  break;

	case 5:
		qsort(employee, 10, sizeof(Employee), comparePhone);  break;
	}
	fp2 = fopen("Result.txt", "w");
	if (fp2 == NULL)

	{
		printf("\n ���� �б� ����2\n");
		exit(1);
	}
	for (i = 0; i < 10; i++) {
		fprintf(fp2, "%-6s %-20s", "�̸�: ", employee[i].name);
		fprintf(fp2, "%-6s %-20d", "���: ", employee[i].num);
		fprintf(fp2, "%-6s %-20d", "�������: ", employee[i].birth);
		fprintf(fp2, "%-6s %-20s", "�μ���: ", employee[i].dept);
		fprintf(fp2, "%10s %-12s\n", "��ȭ��ȣ: ", employee[i].phone);
	}
	printf("���ĿϷ�");
	fclose(fp2);
	return 0;
}