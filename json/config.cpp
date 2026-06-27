#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;


struct ModelConfig
{
    std::string model_name;
    int batch_size;
    bool use_gpu;
};


void to_json(json& j, const ModelConfig& config) {
    j = {
        {"model_name", config.model_name},
        {"batch_size", config.batch_size},
        {"use_gpu", config.use_gpu}
    };
}

void from_json(const json& j, ModelConfig& config) {
    j.at("model_name").get_to(config.model_name);
    j.at("batch_size").get_to(config.batch_size);
    j.at("use_gpu").get_to(config.use_gpu);
}

int main() {

    json j;

    ModelConfig config{"GPT-5", 4, true};

    to_json(j, config);

    std::cout << j.dump(4) << std::endl;

    {
        std::ofstream file("config.json");
        // Записываем JSON в файл
        file << j.dump(4);
    }

    // Читаем JSON из файла
    std::ifstream input_file("config.json");
    json input_j;
    input_file >> input_j;

    ModelConfig config_loaded = input_j.get<ModelConfig>();

    std::cout
    << config_loaded.model_name << '\n'
    << config_loaded.batch_size << '\n'
    << config_loaded.use_gpu << '\n';
}
