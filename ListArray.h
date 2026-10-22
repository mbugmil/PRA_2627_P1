#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#include "List.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;

		static const int MINSIZE = 2;
		void resize(int new_size){
			if(new_size < MINSIZE){
				new_size < MINSIZE;
			}
			for (int i = 0; i < n; i++){
				nuevo[i] = arr[i];
			}
			delete[] arr;
			arr = nuevo;
			max = new_size;
		}
	public:
		ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0){}
		~ListArray() override{
			delete[] arr;
		}
		void insert(int pos, const T& e) override{
			if (pos < 0 || pos > n){
				throw std::out_of_range("ListArray::insert:posicion valida");
			}
			if (n == max){
				resize(max*2);
			}
			for (int i = n; i > pos; --i){
				arr[i] = arr[i-1];
			}
		}
		
		void append(const T& e) override{
			insert(n, e);
		}
		
		void prepend(xonst T& e) override{
			insert(0, e);
		}

		T remove(int pos) override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("ListArray::remove:posicion invalida");
			}

			T eliminado = arr[pos];

			for(int i = pos; i < n - 1; ++i){
				arr[i] = arr[i + 1];
			}

			--n;

			if (max > MINSIZE && n <= max/4){
				resize(max/2);
			}
			return eliminado;
		}

		T get(int pos) const override {
			if (pos < 0 || pos >= n){
				throw std::out_of_range("ListArray::get:posicion invalida");
			}
			return arr[pos];
		}

		T operator[](int pos) cnst {
			return get(pos);
		}
		
		int search(const T& e) const override{
			for (int i = 0; i < n; ++i){
				if (arr[i] == e){
					return i;
				}
			}

			return -1;
			
		}

		bool empty() const override{
			return n == 0;
		}

		int size() const override{
			return n;
		}

		friend std::ostream& operator << (std::ostream& os, const ListArray<T>& lista){
			os << "[";
			for (int i = 0; i < lista.n; ++i){
				if (i > 0){
					os << ", ";
				}
				os << lista.arr[i];
			}
			os << "[";
			return os;
		}
};

#endif
