#include <iostream>
#include <sstream>
#include <chrono>
using namespace std;

struct list {
	int data;
	list* head;
	list* tail;
};

list* new_node(list* prev) {
	list* curr = new list;
	if (prev) prev->tail = curr;
	curr->head = prev, curr->tail = 0;
	return curr;
}

list* list_of_nodes(string list_numbers, list* beg) {
	cout << "Введите целочисленные значения через пробел\n>>";
	cin.ignore();
	getline(cin, list_numbers);
	int node;
	auto start_time = chrono::high_resolution_clock::now();
	stringstream ss(list_numbers);
	if (!ss) {
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Создан пустой лист\n";
		cout << "Время выполнения: " << duration << " мкс" << "\n";
		return 0;
	}
	while (ss >> node) {
		beg = new_node(beg);
		beg->data = node;
	}
	if (ss.fail() && !ss.eof()) {
		cout << "Некорректный ввод\n";
		return 0;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	if (beg) {
		while (beg->head) {
			beg = beg->head;
		}
	}
	cout << "Время выполнения: " << duration << " мкс" << "\n";
	return beg;
}

list* create_list(int len) {
	list* curr = NULL, * next = NULL;
	for (int i = 0; i < len; i++) {
		curr = new list;
		curr->tail = next;
		if (next) {
			next->head = curr;
		}
		next = curr;
	}
	if (curr) curr->head = NULL;
	return curr;
}

list* completed_list(int len, list* beg) {
	auto start_time = chrono::high_resolution_clock::now();
	beg = create_list(len);
	list* curr = beg;
	while (curr) {
		curr->data = rand() % 100;
		curr = curr->tail;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	cout << "Время выполнения: " << duration << " мкс" << endl;
	return beg;
}

void list_output(list* beg) {
	cout << "\n[ ";
	do {
		if (!beg) {
			cout << "ПУСТОЙ ЛИСТ ]\n>>";
			return;
		}
		cout << beg->data << " ";
		beg = beg->tail;
	} while (beg);
	cout << "]\n>>";
}

list* clear_memory(list*& beg) {
	while (beg) {
		list* next = beg->tail;
		delete beg;
		beg = next;
	}
	return beg;
}

int index_output_for_incert(list* beg) {
	int i = 1;
	cout << "\n[ ";
	while (beg) {
		cout << i << " ";
		beg = beg->tail;
		i++;
	}
	cout << i << " ]\n>>";
	return i;
}

void list_output_for_swap(list* beg) {
	int i = 1;
	cout << "\n[ ";
	do {
		if (!beg) {
			cout << "ПУСТОЙ ЛИСТ ]\n>>";
			return;
		}
		cout << beg->data << "(" << i << ")" << " ";
		beg = beg->tail;
		i++;
	} while (beg);
	cout << "]\n>>";
}

void index_output_for_delete(list* beg) {
	int i = 1;
	cout << "\n[ ";
	while (beg) {
		cout << i << " ";
		beg = beg->tail;
		i++;
	}
	cout << "]\n>>";
}



int find_element(list* beg, int index, int value) {
	auto start_time = chrono::high_resolution_clock::now();
	int i = 1;
	if (index != 0) {
		while (beg) {
			if (index == i) {
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return beg->data;
			}
			i++;
			beg = beg->tail;
		}
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return 0;
	}
	else {
		while (beg) {
			if (beg->data == value) {
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return i;
			}
			i++;
			beg = beg->tail;
		}
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return 0;
	}
}

bool delete_element(list*& beg, int index, int value) {
	auto start_time = chrono::high_resolution_clock::now();
	int i = 1;
	list* prev = NULL, * next = NULL, * curr = beg;
	while (beg) {
		if (index != 0) {
			if (i == index) {
				prev = beg->head;
				if (prev) {
					prev->tail = beg->tail;
				}
				if (beg->tail) {
					next = beg->tail;
					next->head = beg->head;
				}
				delete beg;
				if (!prev) beg = next;
				else beg = curr;
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return 1;
			}
		}
		else {
			if (beg->data == value) {
				prev = beg->head;
				if (prev) {
					prev->tail = beg->tail;
				}
				if (beg->tail) {
					next = beg->tail;
					next->head = beg->head;
				}
				delete beg;
				if (!prev) beg = next;
				else beg = curr;
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return 1;
			}
		}
		beg = beg->tail;
		i++;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	cout << "Время выполнения: " << duration << " мкс" << endl;
	beg = curr;
	return 0;
}

int length(list* beg) {
	int i = 0;
	while (beg) {
		i++;
		beg = beg->tail;
	}
	return i;
}

list* incert_element(list*& beg, int index, int value) {
	auto start_time = chrono::high_resolution_clock::now();
	int i = 1;
	list* curr = beg, * begin = curr;
	if (!beg) {
		list* new_element = new list;
		new_element->data = value;
		new_element->tail = 0, new_element->head = 0;
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return new_element;
	}
	while (beg) {
		if (i == index) {
			list* new_element = new list, * prev = beg->head;
			new_element->data = value;
			if (prev) prev->tail = new_element;
			beg->head = new_element;
			new_element->head = prev;
			new_element->tail = beg;
			if (!prev) {
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return new_element;
			}
			else {
				auto end_time = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
				cout << "Время выполнения: " << duration << " мкс" << endl;
				return curr;
			}
		}
		beg = beg->tail;
		i++;
	}
	while (curr->tail) {
		curr = curr->tail;
	}
	list* new_element = new list;
	new_element->data = value;
	curr->tail = new_element;
	new_element->head = curr;
	new_element->tail = NULL;
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	cout << "Время выполнения: " << duration << " мкс" << endl;
	return begin;
}

list* swap_elements(int element1, int element2, list* beg) {
	auto start_time = chrono::high_resolution_clock::now();
	list* curr = beg, * e1 = NULL, * e2 = NULL;
	int i = 1;
	while (curr) {
		if (i == element2) e2 = curr;
		if (i == element1) e1 = curr;
		curr = curr->tail;
		i++;
	}
	if (!e1 || !e2) {
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Не существует элемента для замены\n";
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return beg;
	}
	list* prev1 = e1->head, * next1 = e1->tail, * prev2 = e2->head, * next2 = e2->tail;
	if (next1 == e2) {
		e2->tail = e1;
		e2->head = prev1;
		e1->tail = next2;
		e1->head = e2;
		if (next2) next2->head = e1;
		if (prev1) prev1->tail = e2;
	}
	else if (next2 == e1) {
		e1->tail = e2;
		e1->head = prev2;
		e2->tail = next1;
		e2->head = e1;
		if (next1) next1->head = e2;
		if (prev2) prev2->tail = e1;
	}
	else {
		if (prev1) prev1->tail = e2;
		e2->tail = next1;
		if (prev2) prev2->tail = e1;
		e1->tail = next2;
		e2->head = prev1;
		if (next2) next2->head = e1;
		e1->head = prev2;
		if (next1) next1->head = e2;
	}
	if (e1 == beg) {
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return e2;
	}
	if (e2 == beg) {
		auto end_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
		cout << "Время выполнения: " << duration << " мкс" << endl;
		return e1;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	cout << "Время выполнения: " << duration << " мкс" << endl;
	return beg;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "МЕНЮ\n\t1. Создать двусязный линейный список\n\t2. Вывести список\n\t3. Найти элемент списка\n\t4. Удалить элемент списка\n\t5. Вставить элемент в список\n\t6. Поменять элементы местами\n\t0. Остановить работу программы\n>>";
	int point, len, cursor;
	list* beg = NULL;
	cin >> cursor;
	while (cursor) {
		switch (cursor) {
		case 1: {
			cout << "Выберите способ создания двусвязного линейного списка:\n\t1.Заполнение вручную\n\t2.Заполнение случайными значениями\n\n>>";
			cin >> point;
			switch (point)
			{
			case 1:
			{
				string list_numbers;
				beg = list_of_nodes(list_numbers, beg);
				list_output(beg);
				break;
			}
			case 2:
			{
				cout << "Введите длинну списка\n>>";
				cin >> len;
				if (cin.fail() || len < 0) {
					cout << "Некоректный ввод\n>>";
					break;
				}
				if (len == 0) {
					cout << "Создан пустой лист\n";
				}
				beg = completed_list(len, beg);
				list_output(beg);
				break;
			}
			default:
			{
				cout << "Некорректный ввод\n>>";
				break;
			}
			}
			break;
		}
		case 2:
		{
			list_output(beg);
			break;
		}
		case 4:
		{
			if (!beg) {
				cout << "Ошибка (пустой лист)\n>>";
				break;
			}
			int key, index = 0, value = 0;
			cout << "Удаление элемента по индексу(1) или по значению(2)\n>>";
			cin >> key;
			if (key != 1 && key != 2 || cin.fail()) {
				cout << "Некорректный ввод\n>>";
				break;
			}
			else if (key == 1) {
				index_output_for_delete(beg);
				cin >> index;
			}
			else {
				list_output(beg);
				cin >> value;
			}
			if (delete_element(beg, index, value)) {
				cout << "Элемент был удален\n";
			}
			else {
				cout << "Элемент не найден\n";
			}
			list_output(beg);
		}
		break;
		case 3:
		{
			if (!beg) {
				cout << "Ошибка (пустой лист)\n>>";
				break;
			}
			int key, index = 0, value = 0;
			cout << "Поиск элемента по индексу(1) или по значению(2)\n>>";
			cin >> key;
			cout << ">>";
			if (key != 1 && key != 2 || cin.fail()) {
				cout << "Некорректный ввод\n>>";
				break;
			}
			else if (key == 1) cin >> index;
			else cin >> value;
			int find;
			if (find = find_element(beg, index, value)) {
				if (index != 0) cout << "Элемент с индексом " << index << " найден и содержит значение " << find << "\n>>";
				else cout << "Элемент со значением " << value << " найден и находится по индексом " << find << "\n>>";
			}
			else {
				cout << "Элемент не найден\n>>";
			}
			break;
		}
		case 5:
		{
			cout << "на какое место нужно вставить элемент?\n";
			int k;
			k = index_output_for_incert(beg);
			int index = 0, value, i = 1;
			cin >> index;
			if (index > k || index <= 0) {
				cout << "Элемента не существует\n>>";
				break;
			}
			len = length(beg);
			for (; i < len + 1; i++) {
				if (i == index) break;
			}
			if (i == len + 2) {
				cout << "Невозможно вставить элемент с данным индексом\n>>";
				break;
			}
			else {
				cout << "Введите элемент для вставки\n>>";
				cin >> value;
				if (cin.fail()) {
					cout << "Некоректный ввод\n>>";
					break;
				}
				beg = incert_element(beg, index, value);
				list_output(beg);
			}
			break;
		}
		case 6:
		{
			if (!beg) {
				cout << "Ошибка (пустой лист)\n>>";
				break;
			}
			else if (!beg->tail) {
				cout << "Ошибка (один элемент в списке)\n>>";
				break;
			}
			int e1, e2;
			list_output_for_swap(beg);
			cout << "Введите индексы элементов, которые нужно поменять местами (индексы выделены скобками)\n>>";
			cin >> e1 >> e2;
			if (cin.fail()) {
				cout << "Некоректный ввод\n>>";
				break;
			}
			else {
				beg = swap_elements(e1, e2, beg);
				list_output(beg);
			}
			break;
		}
		default:
		{
			cout << "Некоректный ввод\n>>";
			break;
		}
		}
		cin >> cursor;
		if (cursor == 1) beg = clear_memory(beg);
	}
	clear_memory(beg);
	return 0;
}