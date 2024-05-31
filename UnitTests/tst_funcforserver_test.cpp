#include "../server/aes.h"
#include "../server/dijkstra.h"
#include "../server/dichotomymethod.h"
#include "../server/sha512.h"
#include <QtTest>


class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();
    std::vector<int> parseInput(const std::string& input);

private slots:
    void test_1_sha512();
    void test_2_aes();
    void test_3_dijkstra();
    void test_4_dichotomymethod();
};

FuncForServer_Test::FuncForServer_Test()
{

}

FuncForServer_Test::~FuncForServer_Test()
{

}

std::vector<int> FuncForServer_Test::parseInput(const std::string& input) {
    std::vector<int> result;
    std::stringstream ss(input);
    std::string temp;
    while (getline(ss, temp, '&')) {
        if (!temp.empty() && isdigit(temp[0])) {
            result.push_back(stoi(temp));
        }
    }
    return result;
}

void FuncForServer_Test::test_1_sha512() {
    QString sha512_password = QString::fromStdString(sha512("thisispassword"));
    QVERIFY2(sha512_password == "a4bf53e7219f0789515ec9333f614ea48084605289ce8a7219837ff1237302eccc7757fce1f8fc49cf71a4987c7ba2a6ea43102476c361016735c725189880e2", "Error Test 1: SHA512");
}

void FuncForServer_Test::test_2_aes() {
    unsigned char key[16] = "123456789012345";
    AES aes(key);
    QByteArray encryptedText = aes.encrypt("thisismessage");
    QVERIFY2(encryptedText == "ae3593fa44de6dcbd008b49282865b29", "Error Test 2: AES");
}

void FuncForServer_Test::test_3_dijkstra() {
    std::string input = "check&task_2&1&0&1&1&9&8&1&3&9&9&6&8&";
    std::vector<int> values = parseInput(input);

    int s = values[0];
    int t = values[1];

    std::vector<std::vector<int>> graph(NUM_VERTICES, std::vector<int>(NUM_VERTICES, INF));
    int index = 2;
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            if (i == j) {
                graph[i][j] = INF;
            } else if (i < j) {
                graph[i][j] = values[index++];
                graph[j][i] = graph[i][j];
            }
        }
    }
    int result_deikstra = dijkstra(s, t, graph);
    QVERIFY2(result_deikstra == 1, "Error Test 3: Dijkstra");
}

void FuncForServer_Test::test_4_dichotomymethod() {
    double dichotomy = dichotomyFind(-5, 10, 5, 1, 1, 1);
    QVERIFY2(dichotomy == 9.53125, "Error Test 4: Dichotomy Method");
}

QTEST_APPLESS_MAIN(FuncForServer_Test)

#include "tst_funcforserver_test.moc"
