#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class student {
public:
	std::vector<std::string> data;
	//конструктор
	student(std::string file_name) {
		std::string line; //передаются значения каждой строки из файла сначала в неё, и передаются последовательно
		std::ifstream fout(file_name);
		while (std::getline(fout, line)) {//идёт по всем непустым строкам файла, пока они не закончатся
			//не берёт символ перевода на новую строку. который не нужен
			data.push_back(line);
		}
		fout.close();
	}

	void add(std::string id, std::string name, std::string surname, std::string patronymic, std::string ass, std::string s)
	{
		data.push_back(id);
		data.push_back(name);
		data.push_back(surname);
		data.push_back(patronymic);
		data.push_back(ass);
		data.push_back(s);
	}

	bool empty() {
		return data.empty();
	}

	void showstudents() {
		//int count = 1;
		for (std::string i : data) {
			std::cout << i << '\n';
			//count++;
			/*if (count == 7) {
				std::cout << "+++d+++++++++++++++++++++++++\n";
				count = 1;
			}*/

			//count++;
		}
	}

	void search(int temp, std::string input) {
		for (int i = (temp - 1); i <= data.size() - 6; i = +6) {
			if (data[i] == input) {
				int index = (i / 6) * 6;
				std::cout << "++++++++++++++++++++++++++++++++++\n";
				std::cout << "id: " << data[index] << '\n';
				std::cout << "name: " << data[index + 1] << '\n';
				std::cout << "surname: " << data[index + 2] << '\n';
				std::cout << "patronymic: " << data[index + 3] << '\n';
				std::cout << "average score: " << data[index + 4] << '\n';
				std::cout << "specialization: " << data[index + 5] << '\n';
				std::cout << "+++++++++++++++++++++++++++++++++++\n";
				break;
			}
		}
	}

	void searchname(int temp, std::string name, std::string surname, std::string patronymic) {
		for (int i = (temp - 1);i <= data.size() - 5; i = +5) {
			if ((data[i] == name) && (data[i + 1] == surname) && (data[i + 2] == patronymic)) {
				std::cout << "++++++++++++++++++++++++++++\n";
				std::cout << "id : " << data[i - 1] << '\n';
				std::cout << "name: " << data[i] << '\n';
				std::cout << "surname: " << data[i + 1] << '\n';
				std::cout << "patronymic: " << data[i + 2] << '\n';
				std::cout << "average score: " << data[i + 3] << '\n';
				std::cout << "specialization: " << data[i + 4] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;


			}


		}
	}

	void searchaversc(int temp, std::string input) {
		for (int i = (temp + 1); i <= data.size() - 2; i = +2) {
			if (data[i] == input) {
				int index = (i / 6) * 6;
				std::cout << "++++++++++++++++++++++++++++\n";
				std::cout << "id: " << data[index] << '\n';
				std::cout << "name: " << data[index + 1] << '\n';
				std::cout << "surname: " << data[index + 2] << '\n';
				std::cout << "patronymic: " << data[index + 3] << '\n';
				std::cout << "average score: " << data[index + 4] << '\n';
				std::cout << "specialization: " << data[index + 5] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;
			}
		}
	}

	void search_spec(int temp, std::string input) {
		for (int i = (temp + 1); i <= data.size() - 1; i = +1) {
			if (data[i] == input) {
				int index = (i / 6) * 6;
				std::cout << "++++++++++++++++++++++++++++\n";
				std::cout << "id: " << data[index] << '\n';
				std::cout << "name: " << data[index + 1] << '\n';
				std::cout << "surname: " << data[index + 2] << '\n';
				std::cout << "patronymic: " << data[index + 3] << '\n';
				std::cout << "average score: " << data[index + 4] << '\n';
				std::cout << "specialization: " << data[index + 5] << '\n';
				std::cout << "++++++++++++++++++++++++++++\n";
				break;
			}
		}
	}

	void Delete(std::string del) {
		for (int i = 0; i <= data.size() - 6; i = +6) {

			if (data[i] == del) {
				int begin = i;
				int end = i + 5;
				for (int index = begin; index <= end; )
				{
					data.erase(data.begin() + index);
				}
			}
		}
		std::cout << "you successfully got rid of this itmoshnik! clear job.";
	}

	void filework(std::string file_name) {
		std::ofstream fout(file_name);
		/*int count = 1;*/
		for (std::string info : data) { //специальный цикл, который проходит строго все значения в векторе. перременная сразу получает значения в каждой ячейке последовательно без необходимости передавать самостоятельно инфу в переменную через индексацию
			fout << info << '\n';
			/*count++;
			if (count == 7) {
				fout << "\n" << '\n';
				count = 1;
			}*/

			//count++;
		}
	}

};

int main() {
	const std::string file_name = "students.txt";
	std::ifstream fout("students.txt");
	if (fout.is_open())
	{
		std::cout << "your itmoshniki must be here!\n";
	}
	else
	{
		std::cout << "file opening error\n";
	}
	fout.close(); //закрытие файла

	student data(file_name);

main_menu: //понадобится для гоу ту
	int choice;
	std::cout << "which option do you want to do? choose number:\n"
		<< " 1 - add a student\n"
		<< " 2 - show all students\n"
		<< " 3 - find a student\n"
		<< " 4 - remove a student\n"
		<< " enter your choice:\n";
	std::cin >> choice;
	switch (choice) {
	case 1: {
		std::cout << "enter your student's id: ";
		std::string id;
		std::cin >> id;

		std::cout << "enter your student's  name: ";
		std::string name;
		std::cin >> name;

		std::cout << "enter your student's  surname: ";
		std::string surname;
		std::cin >> surname;

		std::cout << "enter your student's  patronymic: ";
		std::string patronymic;
		std::cin >> patronymic;

		std::cout << "enter your student's average score: ";
		std::string ass;
		std::cin >> ass;

		std::cout << "enter your student's specialization: ";
		std::string s;
		std::cin >> s;

		data.add(id, name, surname, patronymic, ass, s);

		break;
	}
	case 2:
		if (data.empty())
			std::cout << "the list is empty.\n";
		else
			data.showstudents();

		break;

	case 3:
		int num_of_parametr;
		std::cout << "select the parameter that will be used for the search\n";
		std::cout << "select 1 to search by id\n";
		std::cout << "select 2 to search by full name\n";
		std::cout << "select 3 to search by average score\n";
		std::cout << "select 4 to search by specialization\n";

		std::cin >> num_of_parametr;
		std::cout << "\n";

		if (num_of_parametr == 1) {
			std::string id;
			std::cout << "enter id to find student:\n";
			std::cin >> id;

			data.search(num_of_parametr, id);
		}

		else if (num_of_parametr == 2) {
			std::string name;
			std::string surname;
			std::string patronymic;
			std::cout << "enter name to find student:\n";
			std::cin >> name;
			std::cout << "enter surname to find student:\n";
			std::cin >> surname;
			std::cout << "enter patronymic to find student:\n";
			std::cin >> patronymic;
			data.searchname(num_of_parametr, name, surname, patronymic);
		}

		else if (num_of_parametr == 3) {
			std::string ass;
			std::cout << "enter average score to find student:\n";
			std::cin >> ass;

			data.searchaversc(num_of_parametr, ass);
		}

		else if (num_of_parametr == 4) {
			std::string s;
			std::cout << "enter specialization to find student:\n";
			std::cin >> s;

			data.search_spec(num_of_parametr, s);
		}
		break;

	case 4: {
		std::string find_del_identy;
		std::cout << "shoose id of student you want to remove:\n";
		std::cin >> find_del_identy;

		data.Delete(find_del_identy);

		break;
	}
	default:
		std::cout << "invalid choice. please try again.\n";
		goto main_menu;
	}

	int continue_choice;
	std::cout << "press 0 to exit\n";
	std::cin >> continue_choice;
	std::cout << "\n";
	if (continue_choice != 0) {
		goto main_menu;
	}
	else {
		data.filework(file_name);
	}
	return 0;
}

//#include<iostream>
//int main() {
//	std::cout << "yer";
//	return 0;
//}