#pragma once
#include <ostream>

template <typename D, typename K> class BTree;
template <typename D, typename K> class BTree_Node
{
private:
	friend BTree<D,K>;
	
protected:
	unsigned char height;
	
	BTree_Node<D, K>* left;
	BTree_Node<D, K>* mid;
	BTree_Node<D, K>* right;
	
	BTree_Node()
	{
		left = mid = right = nullptr;
		height = 0;
	}
	BTree_Node(D data, K key) : BTree_Node()
	{
		this->data = data;
		this->key = key;
		height = 1;
	}

	unsigned char get_height(BTree_Node<D, K>* cur)
	{
		return cur ? cur->height : 0;
	}
	int bal_factor()
	{
		return get_height(right) - get_height(left);
	}
	void fix_height()
	{
		unsigned char height_left = get_height(left);
		unsigned char height_right = get_height(right);
		height = (height_left > height_right ? height_left : height_right) + 1;
	}

	BTree_Node<D, K>* rotate_right()
	{
		BTree_Node<D, K>* new_root = left;
		left = new_root->right;
		new_root->right = this;
		
		fix_height();
		new_root->fix_height();
		
		return new_root;
	}
	BTree_Node<D, K>* rotate_left()
	{
		BTree_Node<D, K>* new_root = right;
		right = new_root->left;
		new_root->left = this;
		
		fix_height();
		new_root->fix_height();
		
		return new_root;
	}

	BTree_Node<D, K>* balance()
	{
		fix_height();
		
		if (bal_factor() == 2)
		{
			if (right->bal_factor() < 0) right = right->rotate_right();
			return rotate_left();
		}
		if (bal_factor() == -2)
		{
			if (left->bal_factor() > 0) left = left->rotate_left();
			return rotate_right();
		}
		
		return this;
	}

	BTree_Node<D, K>* min_node()
	{
		return left ? left->min_node() : this;
	}
	BTree_Node<D, K>* remove_min()
	{
		if (left == nullptr) return right;
		left = left->remove_min();
		return balance();
	}
	
public:
	D data;
	K key;
};


template <typename D, typename K> class BTree
{
protected:
	BTree_Node<D, K>* _root;
	
public:
	BTree()
	{
		this->_root = nullptr;
	}
	BTree(D data, K key) : BTree()
	{
		_root = new BTree_Node<D, K>(data, key);
	}

	bool empty()
	{
		return _root == nullptr;
	}

	BTree_Node<D, K>* root()
	{
		return _root;
	}
	
	BTree_Node<D, K>* add(D data, K key)
	{
		if (_root == nullptr) return _root = new BTree_Node<D, K>(data, key);
		return add_t(data, key, _root);
	}
	BTree_Node<D, K>* del(K key, int index = -1)
	{
		return del_t(key, _root, index);
	}

	bool has(K& key)
	{
		return has_t(key, _root);
	}
	
	D& operator [] (K& key)
	{
		return return_t(key, _root);
	}

	BTree_Node<D, K>* print(BTree_Node<D, K>* cur = nullptr)
	{
		if (cur) return print_t(cur); 
		return print_t(_root);
	}
	
	BTree_Node<D, K>* print(K& key_f, K& key_l)
	{
		
		return (key_f < key_l ? print_range_t(key_f, key_l, _root) : print_range_t(key_l, key_f, _root));
	}

	BTree_Node<D, K>* peek(K& key)
	{
		return peek_t(key, _root);
	}
	
protected:
	BTree_Node<D, K>* add_t(D& data, K& key, BTree_Node<D, K>*& cur)
	{
		if (cur == nullptr) return cur = new BTree_Node<D, K>(data, key);

		if (key < cur->key) cur->left = add_t(data, key, cur->left);
		else if (key > cur->key) cur->right = add_t(data, key, cur->right);
		else
		{
			BTree_Node<D, K>* tmp_cur = cur;
			while (tmp_cur->mid != nullptr) tmp_cur = tmp_cur->mid;
			tmp_cur->mid = new BTree_Node<D, K>(data, key);
		}

		return cur = cur->balance();
	}
	BTree_Node<D, K>* del_t(K& key, BTree_Node<D, K>*& cur, int index = -1)
	{
		if (cur == nullptr) return nullptr;

		if (key < cur->key) cur->left = del_t(key, cur->left);
		else if (key > cur->key) cur->right = del_t(key, cur->right);
		else
		{
			if (cur->mid != nullptr)
			{
				BTree_Node<D, K>* tmp_cur = cur;

				if (index == -1) while (tmp_cur->mid->mid != nullptr) tmp_cur = tmp_cur->mid;
				else for (auto i = 0; i != index && tmp_cur->mid->mid != nullptr; i++, tmp_cur = tmp_cur->mid);
				delete tmp_cur->mid; tmp_cur->mid = nullptr;
				return cur;
			}

			BTree_Node<D, K>* old_left = cur->left;
			BTree_Node<D, K>* old_right = cur->right;
			delete cur;

			if (old_right == nullptr) return old_left;

			BTree_Node<D, K>* min_right = old_right->min_node();
			min_right->right = old_right->remove_min();
			min_right->left = old_left;

			return min_right->balance();
		}

		return cur = cur->balance();
	}

	bool has_t(K& key, BTree_Node<D, K>*& cur)
	{
		if (cur == nullptr) return false;

		if (key < cur->key) return has_t(key, cur->left);
		if (key > cur->key) return has_t(key, cur->right);
		
		return true;
	}

	D& return_t(K& key, BTree_Node<D, K>*& cur)
	{
		if (key < cur->key) return return_t(key, cur->left);
		if (key > cur->key) return return_t(key, cur->right);

		return cur->data;
	}

	BTree_Node<D, K>* print_t(BTree_Node<D, K>*& cur)
	{
		if (cur->left != nullptr) print_t(cur->left);
		std::cout << " " << cur->key << "\n" << *(cur->data) << "\n";
		if (cur->right != nullptr) print_t(cur->right);
		
		return cur;
	}
	
	BTree_Node<D, K>* print_range_t(K& key_f, K& key_l, BTree_Node<D, K>*& cur)
	{
		if (cur->left != nullptr && cur->key > key_f) print_range_t(key_f, key_l, cur->left);
		if (cur->key >= key_f && cur->key <= key_l) std::cout << " " << cur->key << "\n" << *(cur->data) << "\n";
		if (cur->right != nullptr && cur->key < key_l) print_range_t(key_f, key_l, cur->right);

		return cur;
	}
	
	BTree_Node<D, K>* peek_t(K& key, BTree_Node<D, K>*& cur)
	{
		if (cur == nullptr) return nullptr;

		if (key < cur->key) return peek_t(key, cur->left);
		if (key > cur->key) return peek_t(key, cur->right);
		return cur;
	}
	
};