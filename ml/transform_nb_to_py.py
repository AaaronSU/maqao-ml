import nbformat
from nbconvert import PythonExporter
import os

def convert_ipynb_to_py(ipynb_file_path, py_file_path):
    # 读取.ipynb文件
    with open(ipynb_file_path, 'r', encoding='utf-8') as f:
        notebook_content = f.read()
    
    # 将.ipynb文件内容转换为notebook对象
    notebook = nbformat.reads(notebook_content, as_version=4)
    
    # 创建PythonExporter实例
    python_exporter = PythonExporter()
    
    # 使用PythonExporter将notebook对象转换为Python代码
    (body, resources) = python_exporter.from_notebook_node(notebook)
    
    # 将转换后的Python代码写入.py文件
    with open(py_file_path, 'w', encoding='utf-8') as f:
        f.write(body)

def convert_folder_of_ipynbs(input_folder, output_folder):
    # 确保输出文件夹存在
    os.makedirs(output_folder, exist_ok=True)
    
    # 遍历输入文件夹中的所有文件
    for filename in os.listdir(input_folder):
        if filename.endswith('.ipynb'):
            ipynb_file_path = os.path.join(input_folder, filename)
            py_file_path = os.path.join(output_folder, filename.replace('.ipynb', '.py'))
            convert_ipynb_to_py(ipynb_file_path, py_file_path)
            print(f"Converted {ipynb_file_path} to {py_file_path}")

# 示例用法
input_folder = 'ipynb'  # 替换为包含.ipynb文件的文件夹路径
output_folder = 'py'  # 替换为目标.py文件的文件夹路径
convert_folder_of_ipynbs(input_folder, output_folder)
