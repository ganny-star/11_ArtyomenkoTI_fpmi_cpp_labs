#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "time_utility.h"

using TrainId = size_t;

enum class TrainType {
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};

TrainType StringToTrainType(const std::string& type_str);

std::string TrainTypeToString(TrainType type);

class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    Train();
    Train(TrainId id, TrainType type, const std::string& destination,
          std::time_t dispatch_time, std::time_t travelling_time);

    TrainId GetId() const;
    TrainType GetType() const;
    std::string GetDestination() const;
    std::time_t GetDispatchTime() const;
    std::time_t GetTravellingTime() const;

    void SetId(TrainId id);
    void SetType(TrainType type);
    void SetDestination(const std::string& destination);
    void SetDispatchTime(std::time_t dispatch_time);
    void SetTravellingTime(std::time_t travelling_time);

    void Print() const;
    std::time_t GetArrivalTime() const;
    bool IsInTimeRange(std::time_t start_time, std::time_t end_time) const;
};

std::vector<Train> LoadTrainsFromFile(const std::string& filename);
void SortTrainsByDepartureTime(std::vector<Train>& trains);
std::vector<Train> FilterTrainsByTimeRange(const std::vector<Train>& trains,
                                          std::time_t start_time,
                                          std::time_t end_time);
std::vector<Train> FilterTrainsByDestination(const std::vector<Train>& trains,
                                            const std::string& destination);
std::vector<Train> FilterTrainsByTypeAndDestination(const std::vector<Train>& trains,
                                                   TrainType type,
                                                   const std::string& destination);
Train FindFastestTrainToDestination(const std::vector<Train>& trains,
                                   const std::string& destination);
