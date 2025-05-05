Python 3.12.5 (tags/v3.12.5:ff3bc82, Aug  6 2024, 20:45:27) [MSC v.1940 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
class HashTableChaining:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]
        self.comparisons = 0

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        self.comparisons = 1  # Hash function comparison
        index = self.hash_function(key)
        self.table[index].append(key)

    def search(self, key):
        self.comparisons = 1  # Hash function comparison
        index = self.hash_function(key)
        for i, item in enumerate(self.table[index]):
            self.comparisons += 1
            if item == key:
                return True
        return False

    def delete(self, key):
        self.comparisons = 1  # Hash function comparison
        index = self.hash_function(key)
        for i, item in enumerate(self.table[index]):
            self.comparisons += 1
            if item == key:
                self.table[index].remove(key)
                return True
        return False

    def display(self):
        for i, chain in enumerate(self.table):
            print(f"Index {i}: {chain}")
        print(f"Total comparisons: {self.comparisons}")


class HashTableLinearProbing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.comparisons = 0

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        self.comparisons = 1
        index = self.hash_function(key)
        for i in range(self.size):
            new_index = (index + i) % self.size
            self.comparisons += 1
            if self.table[new_index] is None:
                self.table[new_index] = key
                return
        print("Hash table is full! Cannot insert new entry.")

    def search(self, key):
        self.comparisons = 1
        index = self.hash_function(key)
        for i in range(self.size):
            new_index = (index + i) % self.size
            self.comparisons += 1
            if self.table[new_index] is None:
                return False
            if self.table[new_index] == key:
                return True
        return False

    def delete(self, key):
        self.comparisons = 1
        index = self.hash_function(key)
        for i in range(self.size):
            new_index = (index + i) % self.size
            self.comparisons += 1
            if self.table[new_index] == key:
                self.table[new_index] = None
                return True
            if self.table[new_index] is None:
                return False
        return False

    def display(self):
...         for i, key in enumerate(self.table):
...             print(f"Index {i}: {key if key is not None else 'Empty'}")
...         print(f"Total comparisons: {self.comparisons}")
... 
... 
... class TelephoneDirectory:
...     def __init__(self, size, method):
...         self.size = size
...         self.method = method
...         if method == 'chaining':
...             self.table = HashTableChaining(size)
...         elif method == 'linear_probing':
...             self.table = HashTableLinearProbing(size)
...         else:
...             raise ValueError("Invalid method. Choose either 'chaining' or 'linear_probing'.")
... 
...     def insert(self, key):
...         self.table.insert(key)
... 
...     def search(self, key):
...         return self.table.search(key)
... 
...     def delete(self, key):
...         return self.table.delete(key)
... 
...     def display(self):
...         self.table.display()
... 
... 
... def main():
...     method = input("Choose Hashing Method (chaining/linear_probing): ").strip().lower()
...     size = int(input("Enter the size of the table: "))
...     directory = TelephoneDirectory(size, method)
... 
...     while True:
...         print("\n1. Insert")
...         print("2. Search")
...         print("3. Delete")
        print("4. Display")
        print("5. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            key = int(input("Enter key to insert: "))
            directory.insert(key)
        elif choice == 2:
            key = int(input("Enter key to search: "))
            found = directory.search(key)
            print(f"Key {'found' if found else 'not found'}")
        elif choice == 3:
            key = int(input("Enter key to delete: "))
            deleted = directory.delete(key)
            print(f"Key {'deleted' if deleted else 'not found'}")
        elif choice == 4:
            directory.display()
        elif choice == 5:
            break
        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()
