#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Lift  {
private:
    vector<int> order {0};
    vector<int> lift;
    std::vector<std::vector<int>> queues;
    int capacity;

public:
     Lift (std::vector<std::vector<int>> _queues, int _capacity) :
        queues(std::move(_queues)), capacity(_capacity) {}

     vector<int> find_order () {

         while (!no_cmds()) {
                go_up(order.back());
                go_down(order.back());
         }
         put_in_order(0);
         return order;
     }

private:

     bool no_cmds () {
         for (auto &queue : queues)
             if (!queue.empty())
                 return false;

         return lift.empty();
     }

     bool lift_full () {
         return lift.size() == capacity;
     }

     void put_in_order (int val) {
         if (order.back() != val)
             order.push_back(val);
     }

     void go_up (int pos) {
         int last = 0;
         for (int i = pos; i < queues.size(); ++i) {
             bool i_was_here = false;
             for (auto it = lift.begin(); it != lift.end(); ++it)
                 if (*it == i) {
                     last = i;
                     lift.erase(it);
                     i_was_here = true;
                     --it;
                 }

             for (auto it = queues[i].begin(); it != queues[i].end(); ++it) {
                 last = i;
                 if (*it > i) {
                     i_was_here = true;
                     if (!lift_full()) {
                         lift.push_back(*it);
                         queues[i].erase(it);
                         --it;
                     }
                 }
             }
             if (i_was_here )
                 put_in_order(i);
         }

         put_in_order(last);
         for (auto it = queues[last].begin(); it != queues[last].end(); ++it)
             if (!lift_full()) {
                 lift.push_back(*it);
                 queues[last].erase(it);
                 --it;
             }
     }

    void go_down (int pos) {
        int last = 0;
        for (int i = pos; i >= 0; --i) {
            bool i_was_here = false;
            for (auto it = lift.begin(); it != lift.end(); ++it)
                if (*it == i) {
                    last = i;
                    lift.erase(it);
                    i_was_here = true;
                    --it;
                }

            for (auto it = queues[i].begin(); it != queues[i].end(); ++it) {
                last = i;
                if (*it < i) {
                    i_was_here = true;
                    if (!lift_full()) {
                        lift.push_back(*it);
                        queues[i].erase(it);
                        --it;
                    }
                }
            }
            if (i_was_here)
                put_in_order(i);
        }

            put_in_order(last);
        for (auto it = queues[last].begin(); it != queues[last].end(); ++it)
            if (!lift_full()) {
                lift.push_back(*it);
                queues[last].erase(it);
                --it;
            }
    }
};

std::vector<int> the_lift(std::vector<std::vector<int>> queues, int capacity) {

    Lift lift (std::move(queues), capacity);
    return lift.find_order();
}
