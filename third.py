import ctypes

station = ctypes.CDLL('./lib.dll')

station.create_station.argtypes = [ctypes.c_int, ctypes.c_char_p, ctypes.c_double]
station.create_station.restype = ctypes.c_void_p

station.destroy_station.argtypes = [ctypes.c_void_p]

station.get_id.argtypes = [ctypes.c_void_p]
station.get_id.restype = ctypes.c_int

station.get_name.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int]
station.get_name.restype = None

station.set_traffic.argtypes = [ctypes.c_void_p, ctypes.c_double]
station.set_traffic.restype = None

station.get_traffic.argtypes = [ctypes.c_void_p]
station.get_traffic.restype = ctypes.c_double


station_name = ctypes.c_char_p('Strogino'.encode('utf-8'))

stat1 = station.create_station(0, station_name, 30.6)

id = station.get_id(stat1)
print(id)

traffic = station.get_traffic(stat1)
print(traffic)


name = ctypes.create_string_buffer(100)
station.get_name(stat1, name, ctypes.sizeof(name))
print(name.value.decode('utf-8'))



    
option = -1
c = 0
while option != 3:
        option = int(input('\nCan do:\n0) Create new station\n1) Get info\n2) Change the amount of traffic\n3) Delete the station and exit\n'))
        if option == 0:
            in_name = input('Name the station\n')
            stat_name = ctypes.c_char_p(in_name.encode('utf-8'))
            traffic = float(input('Set its traffic\n'))
            try:
                id = int(input('Determine the id\n'))
            except ValueError:
                print('ERROR\n')
                break
            Station = station.create_station(id, stat_name, traffic)
            c+=1
            input('Done!\n')
        elif option == 1:
            if c != 0:
                input("Here's some info about the station:\n")
                Name = ctypes.create_string_buffer(100)
                station.get_name(Station, Name, ctypes.sizeof(Name))
                print('\nName: ' + Name.value.decode('utf-8'))
                print('\nID: ',  station.get_id(Station))
                print('\nTraffic: ',  station.get_traffic(Station))
                print('Done!\n')
            else:
                print('ERROR! No station created yet!\n')
                break
        elif option == 2:
            if c != 0:
                ntrf = float(input('Determine new traffic:\n'))
                station.set_traffic(Station, ntrf)
                print('Done!\n')
            else:
                print('ERROR! No station created yet!\n')
                break
        elif option == 3:
            if c != 0:
                station.destroy_station(Station)
                print('Done!\n')
            else:
                print('ERROR! No station to destroy!\n')
                break
        else:
            print('ERROR! Invlid command choice\n')
            break

