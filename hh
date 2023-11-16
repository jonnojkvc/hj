import requests
import time

def get_weather_data(api_key, latitude, longitude):
    endpoint = f"https://api.weatherbit.io/v2.0/current?key={api_key}&lat={latitude}&lon={longitude}"
    response = requests.get(endpoint)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Error fetching weather data. Status code: {response.status_code}")
        return None

def check_tornado_symptoms(weather_data):
    if weather_data:
        temperature = weather_data["data"][0]["temp"]
        humidity = weather_data["data"][0]["rh"]
        pressure = weather_data["data"][0]["pres"]

        print(f"Temperature: {temperature}°C")
        print(f"Humidity: {humidity}%")
        print(f"Pressure: {pressure} hPa")

        # Add your tornado symptom conditions here
        if temperature > 30.0 and humidity > 70.0 and pressure < 1000.0:
            print("Tornado symptoms detected! Seek shelter.")
        else:
            print("No tornado symptoms detected.")
    else:
        print("Weather data is not available.")

def main():
    api_key = "0ba70b9100b84b2db380a1f831d59082"  # Replace with your actual Weatherbit API key
    latitude = 35.775  # Replace with the latitude of your location
    longitude = -78.638  # Replace with the longitude of your location

    while True:
        weather_data = get_weather_data(api_key, latitude, longitude)
        check_tornado_symptoms(weather_data)
        time.sleep(600)  # Check every 10 minutes (adjust as needed)

if __name__ == "__main__":
    main()
