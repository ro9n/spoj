/**
 * @file 101.fishmonger
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 26 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

const int INF = 1e9 + 7;

struct state {
  int id, cost, time;

  state() {}

  state(int id, int cost, int time) {
    this->id = id, this->cost = cost, this->time = time;
  }

  bool operator<(const state &v) const {
    // priority queue max heap inverse relation
    if (cost == v.cost) return time > v.time;
    return cost > v.cost;
  }
} u;

int main() {
  int n, t;
  while (scanf("%d %d", &n, &t), n & t) {
    int time[n][n], toll[n][n], vis[n][t];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) scanf("%d", &time[i][j]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) scanf("%d", &toll[i][j]);
    memset(vis, 0, sizeof(vis)), vis[0][t] = 1;

    pair<int, int> best = {INF, INF};
    priority_queue<state> q;
    q.push(state(0, toll[0][0], time[0][0]));

    while (!q.empty()) {
      u = q.top(), q.pop();

      if (u.cost > best.ff) continue;
      else if (u.id == n - 1) {
        if (u.cost < best.ff || (u.cost == best.ff && u.time < best.ss)) best = {u.cost, u.time};
      } else {
        for (int v = 0; v < n; ++v) {
          if (u.id == v) continue;
          int t2 = u.time + time[u.id][v], c = u.cost + toll[u.id][v];
          if (t2 <= t && !vis[v][t2]) vis[v][t2] = 1, q.push(state(v, c, t2));
        }
      }
    }

    printf("%d %d", best.ff, best.ss);
  }
  return 0;
}
