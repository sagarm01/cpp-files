#include <iostream>
#include <string>

using namespace std;

class ModelTraier
{
protected:
    virtual void load() = 0;
    virtual void prepare() = 0;
    virtual void train() = 0;
    virtual void evaluate() = 0;
    virtual void saveModel() = 0;

public:
    void templateMethod(const string &path)
    {
        cout << path << endl;
        load();
        prepare();
        train();
        evaluate();
        saveModel();
    }
};

// ───────────────────────────────────────────────────────────
// 2. Concrete subclass: Neural Network
// ───────────────────────────────────────────────────────────
class NeuralNetworkTrainer : public ModelTraier
{
protected:
    void load() override
    {
        cout << "[NeuralNet] Loading data from disk\n";
    }
    
    void prepare() override
    {
        cout << "[NeuralNet] Preprocessing data (normalization, augmentation)\n";
    }
    
    void train() override
    {
        cout << "[NeuralNet] Training Neural Network for 100 epochs\n";
    }
    
    void evaluate() override
    {
        cout << "[NeuralNet] Evaluating accuracy and loss on validation set\n";
    }
    
    void saveModel() override
    {
        cout << "[NeuralNet] Serializing network weights to .h5 file\n";
    }
};

// ───────────────────────────────────────────────────────────
// 3. Concrete subclass: Decision Tree
// ───────────────────────────────────────────────────────────
class DecisionTreeTrainer : public ModelTraier
{
protected:
    void load() override
    {
        cout << "[DecisionTree] Loading CSV data\n";
    }
    
    void prepare() override
    {
        cout << "[DecisionTree] Splitting data into train/test sets\n";
    }
    
    void train() override
    {
        cout << "[DecisionTree] Building decision tree with max_depth=5\n";
    }
    
    void evaluate() override
    {
        cout << "[DecisionTree] Computing classification report (precision/recall)\n";
    }
    
    void saveModel() override
    {
        cout << "[DecisionTree] Saving model to pickle file\n";
    }
};

int main()
{
    cout << "=== Neural Network Training ===\n";
    ModelTraier *nnTrainer = new NeuralNetworkTrainer();
    nnTrainer->templateMethod("data/images/");

    cout << "\n=== Decision Tree Training ===\n";
    ModelTraier *dtTrainer = new DecisionTreeTrainer();
    dtTrainer->templateMethod("data/iris.csv");

    delete nnTrainer;
    delete dtTrainer;

    return 0;
}