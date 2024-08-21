def convert_to_filename(input_str):
    words = input_str.split()[1:]

    index = input_str.split()[0].split('.')[0].zfill(4)

    filename = "_".join(words)

    return f"{index}_{filename}.cpp"

filename = input("Enter the question: ")
filename = convert_to_filename(filename)

print("Enter the code (press Ctrl+C to finish):")
code = ""
while True:
    try:
        line = input()
        code += line + "\n"
    except KeyboardInterrupt:
        break
    except EOFError:
        break

with open(filename, "w") as file:
    file.write(code)

print(f"Create {filename}")