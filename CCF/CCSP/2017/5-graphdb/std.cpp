#include <bits/stdc++.h>
using namespace std;

typedef uint32_t vertex_id_t;
typedef uint32_t edge_id_t;
typedef uint32_t label_id_t;
const uint32_t M = 1000000;

struct Edge {
    vertex_id_t dst;
    label_id_t label;
};

struct AdjacencyList {
    Edge* begin;
    Edge* end;
};

struct DBStorage {
    vertex_id_t vertex_num;
    label_id_t* vertex_labels;
    AdjacencyList* adj_lists;
};

class Timer {
    chrono::time_point<chrono::system_clock> _start =
        chrono::system_clock::now();

   public:
    void start() { _start = std::chrono::system_clock::now(); }
    double cal() {
        std::chrono::duration<double> diff =
            std::chrono::system_clock::now() - _start;
        return diff.count();
    }
    static double current_time() {
        std::chrono::duration<double> val =
            std::chrono::system_clock::now().time_since_epoch();
        return val.count();
    }
};

struct Query {
    int qtype;
    uint32_t params[6];
};

struct GraphDBEngine {
    DBStorage* storage;
    bool* vis;
    void process_db_query(DBStorage* storage) {
        this->storage = storage;
        vis = new bool[storage->vertex_num];

        int q_param_num[] = {2, 2, 3, 4, 6};
        int qnum;
        scanf("%d", &qnum);
        Query* queries = new Query[qnum];
        for (int q_i = 0; q_i < qnum; q_i++) {
            char s[5];
            scanf("%s", s);
            int qtype = atoi(s + 1);
            if (s[0] == 'q')
                qtype += 3;
            qtype -= 1;

            queries[q_i].qtype = qtype;
            for (int i = 0; i < q_param_num[qtype]; i++)
                scanf("%d ", &queries[q_i].params[i]);
            // printf("%s %d\n", s, qtype);
        }

        Timer timer;
        for (int q_i = 0; q_i < qnum; q_i++) {
            switch (queries[q_i].qtype) {
                case 0:
                    process_q0(queries[q_i]);
                    break;
                case 1:
                    process_q1(queries[q_i]);
                    break;
                case 2:
                    process_q2(queries[q_i]);
                    break;
                case 3:
                    process_q3(queries[q_i]);
                    break;
                case 4:
                    process_q4(queries[q_i]);
                    break;
                default:
                    assert(false);
            }
        }
        //        printf("%.3lf\n", timer.cal());

        delete[] queries;
    }

    void process_q0(Query q) {
        auto vl = storage->vertex_labels;
        auto v_num = storage->vertex_num;
        uint32_t a = q.params[0];
        uint32_t b = q.params[1];
        for (uint32_t v_id = 0; v_id < v_num; v_id++) {
            if (vl[v_id] % a == 0) {
                vl[v_id] += b;
                if (vl[v_id] > M)
                    vl[v_id] -= M;
            }
        }
    }

    void process_q1(Query q) {
        uint32_t a = q.params[0];
        uint32_t b = q.params[1];
        for (uint32_t v_id = 0; v_id < storage->vertex_num; v_id++) {
            Edge* begin = storage->adj_lists[v_id].begin;
            Edge* end = storage->adj_lists[v_id].end;
            for (Edge* e = begin; e != end; e++)
                if (e->label % a == 0) {
                    e->label += b;
                    if (e->label > M)
                        e->label -= M;
                }
        }
    }

    void process_q2(Query q) {
        uint32_t a = q.params[0];
        uint32_t b = q.params[1];
        uint32_t c = q.params[2];
        for (uint32_t v_id = 0; v_id < storage->vertex_num; v_id++) {
            if (storage->vertex_labels[v_id] % a != 0)
                continue;
            Edge* begin = storage->adj_lists[v_id].begin;
            Edge* end = storage->adj_lists[v_id].end;
            for (Edge* e = begin; e != end; e++)
                if (e->label % b == 0) {
                    e->label += c;
                    if (e->label > M)
                        e->label -= M;
                }
        }
    }

    void process_q3(Query q) {
        uint32_t ans = 0;
        uint32_t low = q.params[2], high = q.params[3];
        for (uint32_t v_id = q.params[0]; v_id <= q.params[1]; v_id++) {
            Edge* begin = storage->adj_lists[v_id].begin;
            Edge* end = storage->adj_lists[v_id].end;
            for (Edge* e = begin; e != end; e++)
                if (e->label >= low && e->label <= high)
                    ++ans;
        }
        printf("%u\n", ans);
    }

    void process_q4(Query q) {
        typedef std::pair<uint32_t, uint32_t> q_item_t;
        std::queue<q_item_t> que;
        auto s = q.params[0];
        auto d = q.params[1];
        auto a = q.params[2];
        auto b = q.params[3];
        auto x = q.params[4];
        auto y = q.params[5];
        memset(vis, 0, sizeof(bool) * storage->vertex_num);
        uint32_t ans = 0;
        if (a <= storage->vertex_labels[s] && storage->vertex_labels[s] <= b) {
            ans++;
            if (d > 0) {
                que.push(q_item_t(s, 0));
                vis[s] = true;
            }
        }
        while (que.empty() == false) {
            auto qh = que.front();
            que.pop();
            auto v = qh.first;
            auto dis = qh.second;
            auto adj = storage->adj_lists[v];
            for (Edge* e = adj.begin; e != adj.end; e++)
                if (e->label >= x && e->label <= y && !vis[e->dst] &&
                    storage->vertex_labels[e->dst] >= a &&
                    storage->vertex_labels[e->dst] <= b) {
                    ++ans;
                    vis[e->dst] = true;
                    if (dis + 1 < d)
                        que.push(q_item_t(e->dst, dis + 1));
                }
        }
        printf("%u\n", ans);
    }
};

struct DBMemory {
    vertex_id_t vertex_num;
    label_id_t* vertex_labels;
    AdjacencyList* adj_lists;

    edge_id_t edge_num;
    Edge* edges;
};

void read_data(DBMemory* dbm, DBStorage* storage, const char* data_path) {
    FILE* f = fopen(data_path, "r");
    assert(f != NULL);
    fscanf(f, "%u", &dbm->vertex_num);
    dbm->vertex_labels = new vertex_id_t[dbm->vertex_num];
    dbm->adj_lists = new AdjacencyList[dbm->vertex_num];

    for (vertex_id_t v_i = 0; v_i < dbm->vertex_num; v_i++)
        fscanf(f, "%u", &dbm->vertex_labels[v_i]);

    fscanf(f, "%u", &dbm->edge_num);
    dbm->edges = new Edge[dbm->edge_num];
    Edge* p = dbm->edges;
    for (vertex_id_t v_i = 0; v_i < dbm->vertex_num; v_i++) {
        edge_id_t adj_size;
        fscanf(f, "%u", &adj_size);
        dbm->adj_lists[v_i].begin = p;
        p += adj_size;
        dbm->adj_lists[v_i].end = p;
        for (Edge* e = dbm->adj_lists[v_i].begin; e != dbm->adj_lists[v_i].end;
             e++)
            fscanf(f, "%u %u", &e->dst, &e->label);
    }

    storage->vertex_num = dbm->vertex_num;
    storage->vertex_labels = dbm->vertex_labels;
    storage->adj_lists = dbm->adj_lists;

    fclose(f);
}

void destroy_dbm(DBMemory* dbm) {
    delete[] dbm->vertex_labels;
    delete[] dbm->adj_lists;
    delete[] dbm->edges;
}

int main(int argc, char** argv) {
    char* data_path = argv[1];
    DBMemory* dbm = new DBMemory();
    DBStorage* storage = new DBStorage();
    read_data(dbm, storage, data_path);
    GraphDBEngine* engine = new GraphDBEngine();
    engine->process_db_query(storage);
    destroy_dbm(dbm);
    return 0;
}
