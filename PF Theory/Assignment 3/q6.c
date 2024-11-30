#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures Definition
typedef struct {
    float temp;
    float rainfall;
    float wind_speed;
} WeatherForecast;

typedef struct {
    char crop_type[20];
    int growth_stage;
    float yield;
    WeatherForecast *weather;
} Crop;

typedef struct {
    char name[20];
    char op_status[10];
    float fuel_level;
    char activity_schedule[50];
} Equipment;

typedef struct {
    float soil_nutrients;
    float pH_level;
    int pest_activity;
} Sensor;

typedef struct {
    float x_gps;
    float y_gps;
    float soil_health;
    float moisture_level;
    Crop *crop;
    int crop_count;
    Equipment *equip;
    int equip_count;
    Sensor *sensor;
    int sensor_count;
} Field;

typedef struct {
    Field *fields;
    char region_name[20];
    int field_count;
} RegionalHubs;

typedef struct {
    RegionalHubs *rhubs;
    int rhubs_count;
} CentralServer;

// Function to Initialize Weather Forecast
WeatherForecast* create_weather(float temp, float rainfall, float wind_speed) {
    WeatherForecast *weather = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    weather->temp = temp;
    weather->rainfall = rainfall;
    weather->wind_speed = wind_speed;
    return weather;
}

// Function to Initialize a Crop
Crop* create_crops(int count) {
    Crop *crops = (Crop *)malloc(count * sizeof(Crop));
    for (int i = 0; i < count; i++) {
        printf("Enter details for crop %d (type, growth_stage, expected_yield):\n", i + 1);
        scanf("%s %d %f", crops[i].crop_type, &crops[i].growth_stage, &crops[i].yield);
        crops[i].weather = create_weather(30.0 + i, 5.0, 10.0); // Example weather data
    }
    return crops;
}

// Function to Initialize Equipment
Equipment* create_equipment(int count) {
    Equipment *equipment = (Equipment *)malloc(count * sizeof(Equipment));
    for (int i = 0; i < count; i++) {
        printf("Enter details for equipment %d (name, status, fuel_level, activity_schedule):\n", i + 1);
        scanf("%s %s %f %s", equipment[i].name, equipment[i].op_status, &equipment[i].fuel_level, equipment[i].activity_schedule);
    }
    return equipment;
}

// Function to Initialize Sensors
Sensor* create_sensors(int count) {
    Sensor *sensors = (Sensor *)malloc(count * sizeof(Sensor));
    for (int i = 0; i < count; i++) {
        printf("Enter details for sensor %d (soil_nutrients, pH_level, pest_activity):\n", i + 1);
        scanf("%f %f %d", &sensors[i].soil_nutrients, &sensors[i].pH_level, &sensors[i].pest_activity);
    }
    return sensors;
}

// Function to Initialize a Field
Field create_field() {
    Field field;
    printf("Enter field GPS (latitude, longitude), soil_health, and moisture_level:\n");
    scanf("%f %f %f %f", &field.x_gps, &field.y_gps, &field.soil_health, &field.moisture_level);

    printf("Enter number of crops in the field:\n");
    scanf("%d", &field.crop_count);
    field.crop = create_crops(field.crop_count);

    printf("Enter number of equipment in the field:\n");
    scanf("%d", &field.equip_count);
    field.equip = create_equipment(field.equip_count);

    printf("Enter number of sensors in the field:\n");
    scanf("%d", &field.sensor_count);
    field.sensor = create_sensors(field.sensor_count);

    return field;
}

// Function to Initialize a Regional Hub
RegionalHubs create_hub() {
    RegionalHubs hub;
    printf("Enter the region name:\n");
    scanf("%s", hub.region_name);

    printf("Enter number of fields in the hub:\n");
    scanf("%d", &hub.field_count);
    hub.fields = (Field *)malloc(hub.field_count * sizeof(Field));
    for (int i = 0; i < hub.field_count; i++) {
        printf("Enter details for field %d:\n", i + 1);
        hub.fields[i] = create_field();
    }
    return hub;
}

// Function to Initialize the Central Server
CentralServer create_server() {
    CentralServer server;
    printf("Enter number of regional hubs:\n");
    scanf("%d", &server.rhubs_count);
    server.rhubs = (RegionalHubs *)malloc(server.rhubs_count * sizeof(RegionalHubs));
    for (int i = 0; i < server.rhubs_count; i++) {
        printf("Enter details for hub %d:\n", i + 1);
        server.rhubs[i] = create_hub();
    }
    return server;
}

// Function to Display the Data
void display_server(CentralServer server) {
    for (int i = 0; i < server.rhubs_count; i++) {
        printf("Regional Hub: %s\n", server.rhubs[i].region_name);
        for (int j = 0; j < server.rhubs[i].field_count; j++) {
            Field field = server.rhubs[i].fields[j];
            printf("  Field at GPS: (%.2f, %.2f), Soil Health: %.2f, Moisture: %.2f\n", 
                   field.x_gps, field.y_gps, field.soil_health, field.moisture_level);
            for (int k = 0; k < field.crop_count; k++) {
                printf("    Crop %d: %s, Stage: %d, Yield: %.2f\n", k + 1, 
                       field.crop[k].crop_type, field.crop[k].growth_stage, field.crop[k].yield);
            }
            for (int k = 0; k < field.equip_count; k++) {
                printf("    Equipment %d: %s, Status: %s, Fuel Level: %.2f, Schedule: %s\n", k + 1,
                       field.equip[k].name, field.equip[k].op_status, field.equip[k].fuel_level, 
                       field.equip[k].activity_schedule);
            }
            for (int k = 0; k < field.sensor_count; k++) {
                printf("    Sensor %d: Soil Nutrients: %.2f, pH Level: %.2f, Pest Activity: %d\n", k + 1,
                       field.sensor[k].soil_nutrients, field.sensor[k].pH_level, field.sensor[k].pest_activity);
            }
        }
    }
}

// Free Allocated Memory
void free_server(CentralServer server) {
    for (int i = 0; i < server.rhubs_count; i++) {
        for (int j = 0; j < server.rhubs[i].field_count; j++) {
            free(server.rhubs[i].fields[j].crop);
            free(server.rhubs[i].fields[j].equip);
            free(server.rhubs[i].fields[j].sensor);
        }
        free(server.rhubs[i].fields);
    }
    free(server.rhubs);
}

// Main Function
int main() {
    CentralServer server = create_server();
    display_server(server);
    free_server(server);
    return 0;
}

