from setuptools import find_packages, setup

package_name = 'py_subcontroller'

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
    maintainer='robocatsorin',
    maintainer_email='johnjamisonfoth@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'navigator = py_subcontroller.Navigator:main',
            'coin_flip = py_subcontroller.coin_flip_task:main'
        ],
    },
)
