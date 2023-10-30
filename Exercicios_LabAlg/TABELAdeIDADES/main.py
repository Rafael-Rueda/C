lista = [243,23,54,13]

def soma(lista):
    if not lista:
        return 0
    else:
        total = lista[len(lista) - 1] + soma(lista[:-1])
        return total
    
def contar(lista):
    total = 0
    if not lista:
        return 0
    else:
        total = total + 1 + contar(lista[:-1])
    return total

def maior(lista):
    if not lista:
        return None
    else:
        maiorn = lista[0]
        if maior(lista[1:]) != None:
            if maior(lista[1:]) > maiorn:
                maiorn = maior(lista[1:])
    return maiorn

def quicksort(lista):
    if len(lista) <= 1:
        return lista
    
    pivo = lista[0]
    menor = []
    maior = []
    a = 0
    b = 0

    for c in range(len(lista)):
        if c == 0:
            continue
        if lista[c] <= pivo:
            menor.append(lista[c])
        elif lista[c] > pivo:
            maior.append(lista[c])

    return quicksort(menor) + [pivo] + quicksort(maior)

def fibonacci(n):
    fibo = 0
    anterior = 1
    antanterior = 0
    for c in range(1, n + 1):
        antanterior = anterior
        anterior = fibo
        fibo = anterior + antanterior
        yield fibo
