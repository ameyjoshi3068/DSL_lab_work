#include <iostream>
using namespace std;

class ListNode {
public:
	int studRollNo;
	ListNode *next = NULL;

	ListNode(int roll) {
		studRollNo = roll;
	}

};

class StudentsLL {
public:
	ListNode *head;
	StudentsLL() {
		head = NULL;
	}

	void setData() {
		int count, roll;
		ListNode *newNode;

		cout << "How many entries do you want to make ?" << endl;
		cin >> count;

		cout << "Enter the roll number of student 1" << endl;
		cin >> roll;
		newNode = new ListNode(roll);
		head = newNode;
		ListNode *tmpnode = NULL, *prevNode = head;

		for (int i = 1; i < count; i++) {
			cout << "Enter the roll number of student " << i + 1 << endl;
			cin >> roll;

			ListNode *tmpnode2 = head;
			while (tmpnode2) {
				if (tmpnode2->studRollNo == roll) {
					break;
				}
				tmpnode2 = tmpnode2->next;
			}

			if (tmpnode2 == NULL) {
				tmpnode = new ListNode(roll);
				prevNode->next = tmpnode;
				prevNode = tmpnode;

			}
		}
	}

	static void displayData(StudentsLL *list) {
		ListNode *tmpnode = list->head;
		if (!tmpnode)
			cout << "No students belong to category." << '\n';
		cout << "The roll numbers of students are " << endl;
		while (tmpnode) {
			cout << tmpnode->studRollNo << " ";
			tmpnode = tmpnode->next;

		}
		cout << "\n\n\n";
	}
	StudentsLL getComplement(StudentsLL *set2) {
		ListNode *tmpnode = head, *tmpnode2 = set2->head, *newNode =
		NULL;
		StudentsLL *ans = new StudentsLL;
		ListNode *prevnode = ans->head;
		while (tmpnode) {
			int data = tmpnode->studRollNo;
			bool found = false;
			tmpnode2 = set2->head;
			while (tmpnode2) {
				if (tmpnode2->studRollNo == data) {
					found = true;
					break;
				}
				tmpnode2 = tmpnode2->next;
			}
				if (!found) {
					newNode = new ListNode(data);
					if (!ans->head) {
						ans->head = newNode;
						prevnode = ans->head;
					} else {
						prevnode->next = newNode;
						prevnode = newNode;
					}
				}

				tmpnode = tmpnode->next;
			}

		return *ans;
	}

	StudentsLL intersection(StudentsLL *set2) {
		ListNode *tmpnode = head, *tmpnode2 = set2->head, *newNode =
		NULL;
		StudentsLL *ans = new StudentsLL;
		ListNode *prevnode = ans->head;
		while (tmpnode) {
			tmpnode2 = set2->head;
			while (tmpnode2) {
				if (tmpnode2->studRollNo == tmpnode->studRollNo) {
					newNode = new ListNode(tmpnode->studRollNo);
					if (!ans->head) {
						ans->head = newNode;
						prevnode = ans->head;
					} else {
						prevnode->next = newNode;
						prevnode = newNode;
					}
				}
				tmpnode2 = tmpnode2->next;

			}
			tmpnode = tmpnode->next;

		}
		return *ans;
	}

	StudentsLL getUnion(StudentsLL *set2) {
		ListNode *tmpnode = head, *tmpnode2 = set2->head, *newNode =
		NULL;
		StudentsLL *ans = new StudentsLL;
		ListNode *prevnode = ans->head;
		while (tmpnode) {
			newNode = new ListNode(tmpnode->studRollNo);
			if (!ans->head) {
				ans->head = newNode;
				prevnode = ans->head;
			} else {
				prevnode->next = newNode;
				prevnode = newNode;
			}
			tmpnode = tmpnode->next;

		}
		while (tmpnode2) {
			tmpnode = this->head;
			while (tmpnode) {
				if (tmpnode->studRollNo == tmpnode2->studRollNo) {
					break;
				}
				tmpnode = tmpnode->next;
			}

			if (tmpnode == NULL) {
				tmpnode = new ListNode(tmpnode2->studRollNo);
				prevnode->next = tmpnode;
				prevnode = tmpnode;

			}
			tmpnode2 = tmpnode2->next;
		}

		return *ans;
	}

};
int main() {
	StudentsLL vanilla, butterscotch, ans, universal, tmp;

	int index = 9;
	while (index != 0) {
		cout << "------------------Menu--------------------------	" << endl;
		cout << "1) Enter roll numbers of students based on their liking"
				<< endl;
		cout << "2) Display list of students." << endl;
		cout << "3) Set of students who like both vanilla and butterscotch"
				<< endl;
		cout
				<< "4) Set of students who like either vanilla or butterscotch or not both"
				<< endl;
		cout
				<< "5) Number of students who like neither vanilla nor butterscotch"
				<< endl;
		cout << "Enter 0 to exit" << "\n\n";
		cout << "Select an option: " << endl;
		cin >> index;

		switch (index) {
		case 1:
			cout << "Enter details of all students in college: " << "\n";
			universal.setData();
			cout << "Enter details of students liking vanilla: " << "\n";
			vanilla.setData();
			cout << "Enter details of students liking butterscotch: " << "\n";
			butterscotch.setData();
			universal = vanilla.getUnion(&universal);
			universal = butterscotch.getUnion(&universal);
			break;

		case 2:
			cout << "students eating vanilla: " << "\n";
			StudentsLL::displayData(&vanilla);
			cout << "students eating butterscotch: " << "\n";
			StudentsLL::displayData(&butterscotch);
			break;

		case 3:
			cout << "Set of students who like both vanilla and butterscotch: "
					<< "\n";
			ans = vanilla.intersection(&butterscotch);
			StudentsLL::displayData(&ans);
			break;
		case 4:
			cout
					<< "Set of students who like either vanilla or butterscotch or not both: "
					<< "\n";
			tmp = vanilla.intersection(&butterscotch);
			ans = universal.getComplement(&tmp);
			StudentsLL::displayData(&ans);
			break;

		case 5:
			cout
					<< "Set of students who like either vanilla or butterscotch or not both: "
					<< "\n";
			ans = vanilla.getUnion(&butterscotch);
			ans = universal.getComplement(&ans);
			StudentsLL::displayData(&ans);
			break;

		default:
			cout << "Please select valid option" << endl;

		}
	}

	return 0;
}
