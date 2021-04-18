#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T isi;
  int prioritas;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> pNew, pRev, pHelp;
  pNew = new Element<T>;
  pNew->isi = value;
  pNew->prioritas = priority;
  pNew->next = nullptr;

  pRev = nullptr;
  pHelp = q.Head;
  if(q.Head == nullptr){
    q.Head = pNew;
    q.Tail = pNew;
  } else{
    while(pNew->prioritas <= pHelp->prioritas){
      if(pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }
    if(pHelp == q.Head && pNew->prioritas > pHelp->prioritas){
      pNew->next = pHelp;
      q.Head = pNew;
    } else if(pHelp == q.Tail && pNew->prioritas < pHelp->prioritas){
      pHelp->next = pNew;
      q.Tail = pNew;
    } else{
      pRev->next = pNew;
      pNew->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->isi;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delElement;
  if(q.Head == nullptr){
    delElement = nullptr;
  } else if(q.Head->next == nullptr){
    delElement = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  } else{
    delElement = q.Head;
    q.Head = q.Head->next;
    delElement->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
