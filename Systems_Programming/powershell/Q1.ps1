# Step 1: Retrieve all running processes
$allProcesses = Get-Process

# Step 2: Filter processes using more than 100 MB of memory
$filteredProcesses = $allProcesses | Where-Object { $_.WorkingSet64 -gt 100MB }

# Step 3: Sort the filtered processes based on memory usage
$sortedProcesses = $filteredProcesses | Sort-Object WorkingSet64

# Step 4: Convert to HTML
$htmlContent = $sortedProcesses | Select-Object ProcessName, @{Name="MemoryUsageMB"; Expression={ [math]::round($_.WorkingSet64 / 1MB) }} | ConvertTo-Html

# Step 5: Save to a file
$htmlContent | Out-File -FilePath "MemoryIntensiveProcesses.html"
