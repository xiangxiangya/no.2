

#pragma once

#include<iostream>
#include<vector>

template<class T>
class HashBucketNode{
    
public:
    HashBucketNode(const T & date)
    :_date(date)
    ,_pNext(nullptr){
    }

    HashBucketNode<T> * _pNext;
    T _date;
};


template<class T>
class HashBucket{
public:
    
    typedef HashBucketNode<T> Node;

    HashBucket(const int & capacity=10)
    :_size(0){
        _hb.resize(capacity);
    }
    
    Node* Insert(const T&date){
        //检测是否需要扩容
        //计算哈希桶号
        int bucketNo=HashFunc(date);
        //确保元素的唯一性
        Node* pCur=_hb[bucketNo];
        while(pCur){
            if(pCur->_date==date){
                return pCur;
            }
            pCur=pCur->_pNext;
        }
        //插入元素,也就是把新节点挂在桶的起始位置
        pCur=new Node (date);
        pCur->_pNext=_hb[bucketNo];
        _hb[bucketNo]=pCur;
        _size++;
        return pCur;
    }
    
    
    
private:
    int HashFunc(const T &date){
        return date%10;
    }
private:
    std::vector<HashBucketNode<T>*> _hb;//哈希桶
    int _size;//哈希桶的大小
};
