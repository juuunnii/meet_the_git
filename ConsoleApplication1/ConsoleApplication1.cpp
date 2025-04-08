#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class Student {
public:
	std::vector<std::string> students;
	//конструктор
	Student(std::string file_name) {
		std::string line; //передаются значения каждой строки из файла сначала в неё, и передаются последовательно
		std::ifstream fout(file_name);
		while (std::getline(fout, line)) {//идёт по всем непустым строкам файла, пока они не закончатся
			//не берёт символ перевода на новую строку. который не нужен
			students.push_back(line);
		}
		fout.close();
	}

	void Add(std::string id, std::string name, std::string surname, std::string patronymic, std::string ass, std::string s)
	{
		students.push_back(id);
		students.push_back(name);
		students.push_back(surname);
		students.push_back(patronymic);
		students.push_back(ass);
		students.push_back(s);
	}

	bool Empty() {
		return students.empty();
	}

	void ShowStudents() {
		int count = 1;
		for (std::string i : students) {
			std::cout << i << '\n';
			count++;
			/*if (count == 7) {
				std::cout << "+++d+++++++++++++++++++++++++\n";
				count = 1;
			}*/

			//count++;
		}
	}

	void Search(int temp, std::string input) {
		for (int i = (temp - 1); i <= students.size() - 6; i = +6) {
			if (students[i] == input) {
				int index = (i / 6) * 6;
				std::cout << "ID: " << students[index] << '\n';
				std::cout << "Name: " << students[index + 1] << '\n';
				std::cout << "Surname: " << students[index + 2] << '\n';
				std::cout << "Patronymic: " << students[index + 3] << '\n';
				std::cout << "Average score: " << students[index + 4] << '\n';
				std::cout << "Specialization: " << students[index + 5] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;
			}
		}
	}

	void SearchName(int temp, std::string name, std::string surname, std::string patronymic) {
		for (int i = (temp - 1);i <= students.size() - 6; i = +6) {
			if ((students[i] == name) && (students[i + 1] == surname) && (students[i + 2] == patronymic)) {
				std::cout << "ID : " << students[i - 1] << '\n';
				std::cout << "Name: " << students[i] << '\n';
				std::cout << "Surname: " << students[i + 1] << '\n';
				std::cout << "Patronymic: " << students[i + 2] << '\n';
				std::cout << "Average score: " << students[i + 3] << '\n';
				std::cout << "Specialization: " << students[i + 4] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;


			}


		}
	}

	void SearchAverSc_Spec(int temp, std::string input) {
		for (int i = (temp + 1); i <= students.size() - 6; i = +6) {
			if (students[i] == input) {
				int index = (i / 6) * 6;
				std::cout << "ID: " << students[index] << '\n';
				std::cout << "Name: " << students[index + 1] << '\n';
				std::cout << "Surname: " << students[index + 2] << '\n';
				std::cout << "Patronymic: " << students[index + 3] << '\n';
				std::cout << "Average score: " << students[index + 4] << '\n';
				std::cout << "Specialization: " << students[index + 5] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;
			}
		}
	}

	void Delete(std::string del) {
		for (int i = 0; i <= students.size() - 5; i = +5) {
			if (students[i] == del) {
				int begin = i;
				int end = i + 5;
				for (int index = begin; index <= end; )
				{
					students.erase(students.begin() + index);
				}
			}
		}
		std::cout << "You successfully got rid of this itmoshnik! Clear job.";
	}

	void FileWork(std::string file_name) {
		std::ofstream fout(file_name);
		int count = 1;
		for (std::string info : students) { //специальный цикл, который проходит строго все значения в векторе. Перременная сразу получает значения в каждой ячейке последовательно без необходимости передавать самостоятельно инфу в переменную через индексацию
			fout << info << '\n';
			count++;
			if (count == 7) {
				fout << "++++++++++++++++++++++++++++" << '\n';
				count = 1;
			}

			//count++;
		}
	}

};

int main() {
	const std::string file_name = "students.txt";
	std::ifstream fout("students.txt");
	if (fout.is_open())
	{
		std::cout << "Your itmoshniki must be here!\n";
	}
	else
	{
		std::cout << "File opening error\n";
	}
	fout.close(); //закрытие файла

	Student data(file_name);

main_menu: //понадобится для гоу ту
	int choice;
	std::cout << "Which option do you want to do? Choose number:\n"
		<< " 1 - Add a student\n"
		<< " 2 - Show all students\n"
		<< " 3 - Find a student\n"
		<< " 4 - Remove a student\n"
		<< " Enter your choice:\n";
	std::cin >> choice;
	switch (choice) {
	case 1: {
		std::cout << "Enter your student's ID: ";
		std::string id;
		std::cin >> id;

		std::cout << "Enter your student's  name: ";
		std::string name;
		std::cin >> name;

		std::cout << "Enter your student's  surname: ";
		std::string surname;
		std::cin >> surname;

		std::cout << "Enter your student's  patronymic: ";
		std::string patronymic;
		std::cin >> patronymic;

		std::cout << "Enter your student's average score: ";
		std::string ass;
		std::cin >> ass;

		std::cout << "Enter your student's specialization: ";
		std::string s;
		std::cin >> s;

		data.Add(id, name, surname, patronymic, ass, s);

		break;
	}
	case 2:
		if (data.Empty())
			std::cout << "The list is empty.\n";
		else
			data.ShowStudents();

		break;

	case 3:
		int num_of_parametr;
		std::cout << "Select the parameter that will be used for the search\n";
		std::cout << "Select 1 to search by ID\n";
		std::cout << "Select 2 to search by full name\n";
		std::cout << "Select 3 to search by average score\n";
		std::cout << "Select 4 to search by specialization\n";

		std::cin >> num_of_parametr;
		std::cout << "\n";

		if (num_of_parametr == 1) {
			std::string id;
			std::cout << "Enter ID to find student:\n";
			std::cin >> id;

			data.Search(num_of_parametr, id);
		}

		else if (num_of_parametr == 2) {
			std::string name;
			std::string surname;
			std::string patronymic;
			std::cout << "Enter name to find student:\n";
			std::cin >> name;
			std::cout << "Enter surname to find student:\n";
			std::cin >> surname;
			std::cout << "Enter patronymic to find student:\n";
			std::cin >> patronymic;
			data.SearchName(num_of_parametr, name, surname, patronymic);
		}

		else if (num_of_parametr == 3) {
			std::string ass;
			std::cout << "Enter average score to find student:\n";
			std::cin >> ass;

			data.SearchAverSc_Spec(num_of_parametr, ass);
		}

		else if (num_of_parametr == 4) {
			std::string s;
			std::cout << "Enter specialization to find student:\n";
			std::cin >> s;

			data.SearchAverSc_Spec(num_of_parametr, s);
		}
		break;

	case 4: {
		std::string find_del_identy;
		std::cout << "Shoose ID of student you want to remove:\n";
		std::cin >> find_del_identy;

		data.Delete(find_del_identy);

		break;
	}
	default:
		std::cout << "Invalid choice. Please try again.\n";
		goto main_menu;
	}

	int continue_choice;
	std::cout << "Press 0 to exit\n";
	std::cin >> continue_choice;
	std::cout << "\n";
	if (continue_choice != 0) {
		goto main_menu;
	}
	else {
		data.FileWork(file_name);
	}
	return 0;
}
