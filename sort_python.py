import os.path
import time

number = 100.00
delete = 0.01
tab = []


with open('base.txt', 'w') as file:
    while number > 0:
        file.write(str(round(number, 2)) + '\n')
        number -= delete
    if os.path.exists('base.txt'):
        print('Plik został wygenerowany pomyślnie')



if os.path.exists('base.txt'):
    start_time = time.perf_counter()
    with open('base.txt', 'r') as file:
        numbers = [float(line) for line in file]
        for number in numbers:
            tab.append(number)
    end_time = time.perf_counter()
    elapsed_time = end_time - start_time
    print(f"Czas konwersji liczb: {elapsed_time:.10f} sekund")
    start_time = time.perf_counter()
    tab.sort()
    end_time = time.perf_counter()
    elapsed_time = end_time - start_time
    print(f"Czas w którym posortowano liczby: {elapsed_time:.10f} sekund")

    start_time = time.perf_counter()
    with open('output.txt', 'w') as file:
        for number in tab:
            file.write(str(number) + '\n')
    end_time = time.perf_counter()
    elapsed_time = end_time - start_time
    print(f"Czas w którym wpisano liczby do pliku: {elapsed_time:.10f} sekund")
else:
    print('Plik nie istnieje')
