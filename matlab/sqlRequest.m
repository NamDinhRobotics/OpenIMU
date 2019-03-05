function [sqlquery] = sqlRequest(date, subject, sensor, hw_sensor, offset, tabName)
% subject : name or # of the subject depending of what is in the DB
% sensor : name of the sensor
% hw_sensor : name of the host sensor (AppleWatch, Sensoria...)
% date : date requested format string yyyy-mm-dd
% offset is 0 for X, 1 for Y and 2 for Z if applicable (yes for acc no for
% HR)
%tabName: title for the table if request is made for table.

%Example:
% subject = 'P01'
% sensor = 'Accelerometer'
% hw_sensor = 'AppleWatch'
% date = '2019-02-15';


sqlquery = [...
    'SELECT tabSensorsData.data '...
    'AS ' tabName ' '...
    'FROM tabSensorsData '... 
    'WHERE tabSensorsData.id_sensor '...
        'IN ('...
            'SELECT tabSensors.id_sensor '...
            'FROM tabSensors '...
            'WHERE tabSensors.name = ''' sensor ''' '...
            'AND tabSensors.hw_name = ''' hw_sensor ''''...
            ') '...
    'AND tabSensorsData.id_channel '...
        'IN ('...
            'SELECT tabChannels.id_channel '...
            'FROM tabChannels '...
            'WHERE tabChannels.id_sensor '...
                'IN ('...
                    'SELECT tabSensors.id_sensor '...
                    'FROM tabSensors '...
                    'WHERE tabSensors.name = ''' sensor ''' '...
                    'AND tabSensors.hw_name = ''' hw_sensor ''''...
                    ') '...
            'LIMIT 1 '...
            'OFFSET ' num2str(offset) ' '...
            ') '...
    'AND tabSensorsData.id_timestamps '...
        'IN ('...
            'SELECT tabSensorsTimestamps.id_sensor_timestamps '...
            'FROM tabSensorsTimestamps '...
            'WHERE tabSensorsTimestamps.start_timestamp LIKE ''' date '%'' '...
            'OR tabSensorsTimestamps.end_timestamp LIKE ''' date '%'''...
            ') '...
    'AND tabSensorsData.id_recordset '...
        'IN ('...
            'SELECT tabRecordsets.id_recordset '...
            'FROM tabRecordsets '...
            'WHERE tabRecordsets.id_participant '...
                'IN ('...
                    'SELECT tabParticipants.id_participant '...
                    'FROM tabParticipants '...
                    'WHERE tabParticipants.name=''' subject ''''...    
                    ')'...
        ') '...
    'AND tabSensorsData.data IS NOT NULL '...
    ];
end
