import py_sensors.ms5837 as ms5837


_sensor : ms5837.MS5837_02BA

_sensor_units : tuple[  
                        float,          # pressure units
                        int             # temperature units
                    ]


def InitSensor(i2cbus : int = 7,  temperature_units : int = ms5837.UNITS_Centigrade, pressure_units : float = ms5837.UNITS_mbar) -> bool:
    print("initializing sensor")
    global _sensor
    global _sensor_units
    _sensor = ms5837.MS5837_02BA(i2cbus)
    _sensor_units = (temperature_units,pressure_units)

    
    return _sensor.init()


def SetFluidDensity(density = ms5837.DENSITY_FRESHWATER):
    global _sensor
    _sensor.setFluidDensity(density)

# returns tuple (pressure, depth (meters), temperature), -1 for all values means that read was unsuccessful
def ReadSensor() -> tuple[float,float,float]:
    global _sensor
    global _sensor_units
    if _sensor.read():
       pressure = _sensor.pressure(_sensor_units[1])
       depth = _sensor.depth()
       temperature = _sensor.temperature(_sensor_units[0])
       return (pressure,depth,temperature)
    else: return(-1,-1,-1)





