from setuptools import find_packages, setup

package_name = 'num_pubsub'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='num1 + num2 发布订阅示例',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'publisher_node = num_pubsub.publisher_node:main',
            'subscriber_node = num_pubsub.subscriber_node:main',
        ],
    },
)
