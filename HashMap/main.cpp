/*
-- Принцип работы --
Реализация простой хеш-таблицы, в которой все ключи и значения - целые числа. Реализована с помощью вектора, который хранит указатель на элемент списка.
Узел списка содержит ключ, значение и указатель на следующий элемент. Список выбран для разрешения коллизий методом цепочек.
Хеш-таблица поддерживает три метода:
1. get(int key) - получение значения по ключу, если ключа нет в хеш-таблице, то выводит "None". Для получения значения выполняется проход по всем узлам списка с индексом хеша.
2. put(int key, int value) - добавление пары ключ-значение. Если ключ уже есть в таблице, то значение меняется. При коллизии узел списка добавляется в начало.
3. delete_(int key) - удаление элемента из хеш-таблицы по ключу, при удалении выводит хранимое значение, если ключа нет, выводит "None".
Масштабирование и рехеширование не поддерживается

-- Доказательство корректности -- 
Хеш функция обладает четырьмя главными свойствами: детерминизм, эффективность, ограниченность, равномерность. Для борьбы с коллизиями выбран метод цепочек.
На тестовых данных хеш-таблица отработала корректно.

-- Временная сложность -- 
1. Вставка в среднем за O(1), но в худшем случае при большем количестве коллизий, может дойти до O(n), n - количество элементов с таким же значением хеша.
2. Получение элемента в среднем за O(1), также в худшем случае временная сложность будет O(n), n - количество элементов с таким же значением хеша.
3. Удаление элемента в среднем за O(1), также в худшем случае временная сложность будет O(n), n - количество элементов с таким же значением хеша.

-- Пространственная сложность --
Максимальные затраты по памяти будут O(n), n - размер вектора хеш-таблицы. 
Пространственная сложность зависит от количества элементов, которые добавили в таблицу, но не больше n.
*/

#include <iostream>
#include <vector>
#include <optional>

struct ListNode{
    int key;
    int value;
    ListNode* next;
    ListNode(int k, int val) : key(k), value(val), next(nullptr) {}
};

class HashTable{
public:
    HashTable() : hash_map_(MAP_SIZE, nullptr) {}

    ~HashTable(){
        for (auto& head : hash_map_){
            while (head != nullptr){
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void put(int key, int value){
        int hash = Hash(key);
        ListNode* current_list = hash_map_[hash];
        while (current_list != nullptr){
            if (current_list->key == key){
                current_list->value = value;
                return;
            }
            current_list = current_list->next;
        }
        ListNode* new_head = new ListNode(key,value);
        new_head->next = hash_map_[hash];
        hash_map_[hash] = new_head;
    }

    std::optional<int> get(int key){
        int hash = Hash(key);
        ListNode* current_list = hash_map_[hash];
        while (current_list != nullptr){
            if (current_list->key == key){
                return current_list->value;
            }
            current_list = current_list->next;
        }
        return std::nullopt;
    }

    std::optional<int> delete_(int key){
        int hash = Hash(key);
        ListNode* current_list = hash_map_[hash];
        ListNode* prev_list = nullptr;
        while (current_list != nullptr){
            if (current_list->key == key){
                int value = current_list->value;
                if (prev_list == nullptr){
                    hash_map_[hash] = current_list->next;
                }
                else{
                    prev_list->next = current_list->next;
                }
                delete current_list;
                return value;
            }
            prev_list = current_list;
            current_list = current_list->next;
        }
        return std::nullopt;
    }
private:
    const int MAP_SIZE = 1e5 + 7;
    std::vector<ListNode*> hash_map_;

    int Hash(int key){
        int hash = std::hash<int>{}(key) % MAP_SIZE;
        return hash < 0 ? hash + MAP_SIZE : hash;
    }
};

void ApplyCommands(int command_count, HashTable& map){
    for (int i = 0; i < command_count; ++i){
        std::string command;
        int key = 0;
        std::cin >> command;
        if (command == "get"){
            std::cin >> key;
            std::optional<int> result = map.get(key);
            result != std::nullopt ? std::cout << result.value() << "\n" : std::cout << "None\n";
        }
        else if (command == "put"){
            int value = 0;
            std::cin >> key >> value;
            map.put(key, value);
        }
        else if (command == "delete"){
            std::cin >> key;
            std::optional<int> result = map.delete_(key);
            result != std::nullopt ? std::cout << result.value() << "\n" : std::cout << "None\n";
        }
    }
}

int main() {
    HashTable map;
    int query_count = 0;
    std::cin >> query_count;
    std::cin.ignore();
    ApplyCommands(query_count, map);
}