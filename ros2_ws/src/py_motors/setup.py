from setuptools import find_packages, setup

package_name = 'py_motors'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robocats',
    maintainer_email='dhjensen02@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'motor_conductor = py_motors.motor_conductor:main',
            'motor_controller = py_motors.motor_controller:main',
            'keyboard_controller = py_motors.keyboard_input:main',
            'depth_controller = py_motors.depth_controller:main',
            'heading_controller = py_motors.heading_controller:main'
        ],
    },
)
